# メモリ管理ガイドライン

## 1. 基本原則

### 1.1 所有権の明確化
```cpp
// 1. 明示的な所有権移転
void* create_owned_resource() {
    return new Resource();  // 呼び出し側が所有権を持つ
}

// 2. 参照のみを返す
const Resource* get_resource_reference() {
    return &singleton_resource;  // 所有権の移転なし
}
```

### 1.2 リソース管理の責任
```cpp
// 1. 作成者が解放
void* creator_responsible() {
    void* ptr = create_resource();
    use_resource(ptr);
    delete_resource(ptr);  // 作成者が解放
    return nullptr;
}

// 2. 受け取り側が解放
void* receiver_responsible() {
    return create_resource();  // 受け取り側で解放が必要
}
```

## 2. メモリ管理パターン

### 2.1 スコープベースの管理
```cpp
// 1. RAIIパターン
class ScopedResource {
    void* ptr;
public:
    explicit ScopedResource(void* p) : ptr(p) {}
    ~ScopedResource() {
        if (ptr) {
            delete_resource(ptr);
        }
    }
    void* get() const { return ptr; }
    void* release() {
        void* p = ptr;
        ptr = nullptr;
        return p;
    }
private:
    // コピー禁止
    ScopedResource(const ScopedResource&) = delete;
    ScopedResource& operator=(const ScopedResource&) = delete;
};

// 2. 使用例
void use_scoped_resource() {
    ScopedResource res(create_resource());
    // リソースの使用
    use_resource(res.get());
    // スコープ終了時に自動解放
}
```

### 2.2 参照カウント
```cpp
// 1. 参照カウント管理クラス
class RefCounted {
    std::atomic<int> ref_count;
public:
    RefCounted() : ref_count(1) {}
    
    void add_ref() {
        ref_count.fetch_add(1, std::memory_order_relaxed);
    }
    
    void release() {
        if (ref_count.fetch_sub(1, std::memory_order_acq_rel) == 1) {
            delete this;
        }
    }
protected:
    virtual ~RefCounted() = default;
};

// 2. 使用例
class Resource : public RefCounted {
public:
    void do_something() {}
};

void use_ref_counted() {
    Resource* res = new Resource();
    res->add_ref();  // 参照カウント増加
    use_resource(res);
    res->release();  // 参照カウント減少
}
```

## 3. Qt特有のメモリ管理

### 3.1 親子関係の管理
```cpp
// 1. 親オブジェクトの設定
void set_parent_ownership(QWidget* child, QWidget* parent) {
    child->setParent(parent);  // 親が子の寿命を管理
}

// 2. 親子関係の解除
void clear_parent(QWidget* widget) {
    widget->setParent(nullptr);  // 親子関係の解除
}
```

### 3.2 Qtのスマートポインタ
```cpp
// 1. QScopedPointerの使用
QScopedPointer<QWidget> widget(new QWidget());
widget->show();  // スコープ終了時に自動削除

// 2. QSharedPointerの使用
QSharedPointer<QObject> obj = QSharedPointer<QObject>::create();
```

## 4. C APIのメモリ管理

### 4.1 リソース作成/削除
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
```

### 4.2 一時リソースの管理
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

## 5. メモリリーク防止

### 5.1 リソーストラッキング
```cpp
class ResourceTracker {
    static std::unordered_map<void*, std::string> allocations;
    static std::mutex mutex;
public:
    static void track(void* ptr, const std::string& type) {
        std::lock_guard<std::mutex> lock(mutex);
        allocations[ptr] = type;
    }
    
    static void untrack(void* ptr) {
        std::lock_guard<std::mutex> lock(mutex);
        allocations.erase(ptr);
    }
    
    static void dump_leaks() {
        std::lock_guard<std::mutex> lock(mutex);
        for (const auto& [ptr, type] : allocations) {
            fprintf(stderr, "Leak: %p (%s)\n", ptr, type.c_str());
        }
    }
};
```

### 5.2 デバッグ支援
```cpp
// 1. アロケーションカウンタ
class AllocationCounter {
    static std::atomic<size_t> count;
public:
    static void increment() {
        count.fetch_add(1, std::memory_order_relaxed);
    }
    
    static void decrement() {
        count.fetch_sub(1, std::memory_order_relaxed);
    }
    
    static size_t get_count() {
        return count.load(std::memory_order_relaxed);
    }
};

// 2. メモリ使用量トラッカー
class MemoryUsageTracker {
    static std::atomic<size_t> total_bytes;
public:
    static void add_allocation(size_t bytes) {
        total_bytes.fetch_add(bytes, std::memory_order_relaxed);
    }
    
    static void remove_allocation(size_t bytes) {
        total_bytes.fetch_sub(bytes, std::memory_order_relaxed);
    }
    
    static size_t get_total_bytes() {
        return total_bytes.load(std::memory_order_relaxed);
    }
};
```

## 6. スレッドセーフなメモリ管理

### 6.1 スレッドセーフなリソースプール
```cpp
template<typename T>
class ResourcePool {
    std::mutex mutex;
    std::vector<std::unique_ptr<T>> resources;
public:
    T* acquire() {
        std::lock_guard<std::mutex> lock(mutex);
        if (resources.empty()) {
            return new T();
        }
        T* resource = resources.back().release();
        resources.pop_back();
        return resource;
    }
    
    void release(T* resource) {
        if (!resource) return;
        std::lock_guard<std::mutex> lock(mutex);
        resources.emplace_back(resource);
    }
};
```

### 6.2 スレッドローカルストレージ
```cpp
// 1. スレッドローカルバッファ
thread_local char string_buffer[1024];

const char* get_thread_safe_string(const QString& str) {
    QByteArray utf8 = str.toUtf8();
    strncpy(string_buffer, utf8.constData(), sizeof(string_buffer) - 1);
    string_buffer[sizeof(string_buffer) - 1] = '\0';
    return string_buffer;
}

// 2. スレッドローカルリソースキャッシュ
class ThreadLocalCache {
    static thread_local std::unordered_map<std::string, void*> cache;
public:
    static void* get(const std::string& key) {
        return cache[key];
    }
    
    static void put(const std::string& key, void* value) {
        cache[key] = value;
    }
};
