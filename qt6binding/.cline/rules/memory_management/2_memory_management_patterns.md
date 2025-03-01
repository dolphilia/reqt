# メモリ管理パターン

## 2.1 スコープベースの管理
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

## 2.2 参照カウント
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

## 2.3 スマートポインタパターン

### 1. 独占所有権
```cpp
template<typename T>
class UniquePtr {
    T* ptr;
public:
    explicit UniquePtr(T* p = nullptr) : ptr(p) {}
    ~UniquePtr() { delete ptr; }
    
    T* get() const { return ptr; }
    T* release() {
        T* p = ptr;
        ptr = nullptr;
        return p;
    }
    
    void reset(T* p = nullptr) {
        delete ptr;
        ptr = p;
    }
    
private:
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;
};
```

### 2. 共有所有権
```cpp
template<typename T>
class SharedPtr {
    T* ptr;
    std::atomic<int>* ref_count;
    
public:
    explicit SharedPtr(T* p = nullptr)
        : ptr(p), ref_count(p ? new std::atomic<int>(1) : nullptr) {}
    
    SharedPtr(const SharedPtr& other)
        : ptr(other.ptr), ref_count(other.ref_count) {
        if (ref_count) {
            ref_count->fetch_add(1, std::memory_order_relaxed);
        }
    }
    
    ~SharedPtr() {
        if (ref_count && ref_count->fetch_sub(1,
            std::memory_order_acq_rel) == 1) {
            delete ptr;
            delete ref_count;
        }
    }
    
    T* get() const { return ptr; }
};
```

## 2.4 メモリプールパターン

### 1. 固定サイズプール
```cpp
class FixedSizePool {
    struct Block {
        Block* next;
        char data[1];  // 可変サイズ部分
    };
    
    Block* free_list;
    size_t block_size;
    
public:
    explicit FixedSizePool(size_t size)
        : free_list(nullptr), block_size(size) {}
    
    void* allocate() {
        if (!free_list) {
            expand();
        }
        Block* block = free_list;
        free_list = block->next;
        return block->data;
    }
    
    void deallocate(void* ptr) {
        Block* block = reinterpret_cast<Block*>(
            static_cast<char*>(ptr) - offsetof(Block, data));
        block->next = free_list;
        free_list = block;
    }
    
private:
    void expand() {
        // プールの拡張処理
    }
};
```

### 2. オブジェクトプール
```cpp
template<typename T>
class ObjectPool {
    std::vector<T*> free_objects;
    std::mutex mutex;
    
public:
    T* acquire() {
        std::lock_guard<std::mutex> lock(mutex);
        if (free_objects.empty()) {
            return new T();
        }
        T* obj = free_objects.back();
        free_objects.pop_back();
        return obj;
    }
    
    void release(T* obj) {
        if (!obj) return;
        std::lock_guard<std::mutex> lock(mutex);
        free_objects.push_back(obj);
    }
    
    ~ObjectPool() {
        for (T* obj : free_objects) {
            delete obj;
        }
    }
};
```

## 2.5 メモリ管理パターンのガイドライン

### 1. パターンの選択基準
- リソースの寿命
- 所有権の要件
- パフォーマンス要件
- スレッド安全性の要件

### 2. パターンの組み合わせ
- 複数パターンの適切な組み合わせ
- パターン間の相互作用の考慮
- 一貫性の維持
- 複雑さの管理

### 3. エラー処理との統合
- メモリ確保失敗の処理
- リソース解放の保証
- 例外安全性の確保
- エラー状態の伝播

### 4. デバッグとテスト
- メモリリークの検出
- 使用パターンの検証
- エッジケースのテスト
- パフォーマンスの測定
