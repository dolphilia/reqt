# C APIのメモリ管理

## 4.1 リソース作成/削除
```c
// 1. 作成関数
void* Widget_create() {
    try {
        return new QWidget();
    } catch (...) {
        return nullptr;
    }
}

// 2. 削除関数
void Widget_delete(void* ptr) {
    if (ptr) {
        delete static_cast<QWidget*>(ptr);
    }
}

// 3. エラー処理付き作成
void* Widget_create_safe(ErrorInfo* error) {
    try {
        void* ptr = new QWidget();
        if (!ptr) {
            set_error(error, ERROR_MEMORY,
                     "Failed to create widget");
        }
        return ptr;
    } catch (const std::exception& e) {
        set_error(error, ERROR_OPERATION, e.what());
        return nullptr;
    }
}
```

## 4.2 一時リソースの管理
```c
// 1. 文字列バッファ
const char* get_string_content(void* widget) {
    static thread_local char buffer[1024];
    if (!widget) return nullptr;
    
    auto* w = static_cast<QWidget*>(widget);
    QByteArray utf8 = w->windowTitle().toUtf8();
    strncpy(buffer, utf8.constData(), sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    return buffer;
}

// 2. 配列の管理
typedef struct {
    void** items;
    int count;
} ItemArray;

ItemArray* create_item_array() {
    auto* array = new ItemArray();
    array->items = nullptr;
    array->count = 0;
    return array;
}

void delete_item_array(ItemArray* array) {
    if (array) {
        delete[] array->items;
        delete array;
    }
}
```

## 4.3 リソース管理パターン

### 1. 親子関係の管理
```c
// 1. 親の設定
void Widget_setParent(void* widget, void* parent) {
    if (!widget) return;
    auto* w = static_cast<QWidget*>(widget);
    w->setParent(static_cast<QWidget*>(parent));
}

// 2. 親の取得
void* Widget_parent(void* widget) {
    if (!widget) return nullptr;
    auto* w = static_cast<QWidget*>(widget);
    return w->parent();
}

// 3. 子の列挙
ItemArray* Widget_children(void* widget) {
    if (!widget) return nullptr;
    
    auto* w = static_cast<QWidget*>(widget);
    auto children = w->children();
    
    auto* array = create_item_array();
    array->count = children.size();
    array->items = new void*[array->count];
    
    for (int i = 0; i < array->count; ++i) {
        array->items[i] = children[i];
    }
    
    return array;
}
```

### 2. リソースの所有権管理
```c
// 1. 所有権の移転
void* Widget_takeOwnership(void* widget) {
    if (!widget) return nullptr;
    auto* w = static_cast<QWidget*>(widget);
    w->setParent(nullptr);  // 親子関係の解除
    return widget;
}

// 2. 所有権の確認
bool Widget_hasParent(void* widget) {
    if (!widget) return false;
    auto* w = static_cast<QWidget*>(widget);
    return w->parent() != nullptr;
}
```

## 4.4 メモリ管理の実装例

### 1. リソースプール
```c
typedef struct {
    void** items;
    int capacity;
    int count;
    std::mutex mutex;
} ResourcePool;

ResourcePool* create_resource_pool(int initial_capacity) {
    auto* pool = new ResourcePool();
    pool->capacity = initial_capacity;
    pool->count = 0;
    pool->items = new void*[initial_capacity];
    return pool;
}

void* resource_pool_acquire(ResourcePool* pool) {
    std::lock_guard<std::mutex> lock(pool->mutex);
    if (pool->count > 0) {
        return pool->items[--pool->count];
    }
    return create_resource();
}

void resource_pool_release(ResourcePool* pool, void* resource) {
    std::lock_guard<std::mutex> lock(pool->mutex);
    if (pool->count < pool->capacity) {
        pool->items[pool->count++] = resource;
    } else {
        delete_resource(resource);
    }
}

void delete_resource_pool(ResourcePool* pool) {
    if (!pool) return;
    for (int i = 0; i < pool->count; ++i) {
        delete_resource(pool->items[i]);
    }
    delete[] pool->items;
    delete pool;
}
```

### 2. リソースキャッシュ
```c
typedef struct {
    std::unordered_map<std::string, void*> cache;
    std::mutex mutex;
} ResourceCache;

ResourceCache* create_resource_cache() {
    return new ResourceCache();
}

void* resource_cache_get(ResourceCache* cache,
                        const char* key) {
    std::lock_guard<std::mutex> lock(cache->mutex);
    auto it = cache->cache.find(key);
    if (it != cache->cache.end()) {
        return it->second;
    }
    void* resource = create_resource();
    cache->cache[key] = resource;
    return resource;
}

void resource_cache_remove(ResourceCache* cache,
                         const char* key) {
    std::lock_guard<std::mutex> lock(cache->mutex);
    auto it = cache->cache.find(key);
    if (it != cache->cache.end()) {
        delete_resource(it->second);
        cache->cache.erase(it);
    }
}

void delete_resource_cache(ResourceCache* cache) {
    if (!cache) return;
    for (const auto& [key, resource] : cache->cache) {
        delete_resource(resource);
    }
    delete cache;
}
```

## 4.5 メモリ管理のガイドライン

### 1. リソース管理の原則
- 所有権の明確化
- エラー処理の徹底
- リソースリークの防止
- スレッド安全性の確保

### 2. 一時リソースの扱い
- バッファサイズの適切な設定
- スレッドローカルストレージの活用
- オーバーフロー対策
- クリーンアップの確実な実行

### 3. エラー処理
- NULLチェックの徹底
- エラー情報の提供
- 部分的な失敗の処理
- リソースの適切な解放

### 4. デバッグサポート
- メモリリークの追跡
- リソース使用状況の監視
- エラーの検出
- デバッグ情報の提供
