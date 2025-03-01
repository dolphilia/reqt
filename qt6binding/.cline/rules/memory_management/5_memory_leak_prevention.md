# メモリリーク防止

## 5.1 リソーストラッキング
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

## 5.2 デバッグ支援
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

## 5.3 リソース監視システム

### 1. リソースウォッチャー
```cpp
class ResourceWatcher {
    struct ResourceInfo {
        std::string type;
        std::string location;
        size_t size;
        std::chrono::steady_clock::time_point creation_time;
    };
    
    static std::unordered_map<void*, ResourceInfo> resources;
    static std::mutex mutex;
    
public:
    static void watch(void* ptr, const std::string& type,
                     const std::string& location, size_t size) {
        std::lock_guard<std::mutex> lock(mutex);
        resources[ptr] = {
            type,
            location,
            size,
            std::chrono::steady_clock::now()
        };
    }
    
    static void unwatch(void* ptr) {
        std::lock_guard<std::mutex> lock(mutex);
        resources.erase(ptr);
    }
    
    static void report() {
        std::lock_guard<std::mutex> lock(mutex);
        for (const auto& [ptr, info] : resources) {
            auto age = std::chrono::steady_clock::now() -
                      info.creation_time;
            fprintf(stderr,
                "Resource %p:\n"
                "  Type: %s\n"
                "  Location: %s\n"
                "  Size: %zu bytes\n"
                "  Age: %lld ms\n",
                ptr,
                info.type.c_str(),
                info.location.c_str(),
                info.size,
                std::chrono::duration_cast<
                    std::chrono::milliseconds>(age).count());
        }
    }
};
```

### 2. リソースガード
```cpp
template<typename T>
class ResourceGuard {
    T* ptr;
    std::string type;
    std::string location;
    
public:
    ResourceGuard(T* p, const std::string& t,
                 const std::string& loc)
        : ptr(p), type(t), location(loc) {
        if (ptr) {
            ResourceWatcher::watch(ptr, type, location,
                                 sizeof(T));
        }
    }
    
    ~ResourceGuard() {
        if (ptr) {
            ResourceWatcher::unwatch(ptr);
            delete ptr;
        }
    }
    
    T* get() const { return ptr; }
    T* release() {
        T* p = ptr;
        ptr = nullptr;
        if (p) {
            ResourceWatcher::unwatch(p);
        }
        return p;
    }
};
```

## 5.4 メモリリーク検出

### 1. スタックトレース収集
```cpp
class StackTraceCollector {
public:
    static std::string get_stack_trace() {
        std::stringstream ss;
        void* stack[128];
        int frames = backtrace(stack, 128);
        char** symbols = backtrace_symbols(stack, frames);
        
        if (symbols) {
            for (int i = 0; i < frames; ++i) {
                ss << symbols[i] << "\n";
            }
            free(symbols);
        }
        
        return ss.str();
    }
};
```

### 2. メモリリーク検出器
```cpp
class LeakDetector {
    struct AllocationInfo {
        size_t size;
        std::string stack_trace;
        std::chrono::steady_clock::time_point time;
    };
    
    static std::unordered_map<void*,
                             AllocationInfo> allocations;
    static std::mutex mutex;
    
public:
    static void on_allocation(void* ptr, size_t size) {
        std::lock_guard<std::mutex> lock(mutex);
        allocations[ptr] = {
            size,
            StackTraceCollector::get_stack_trace(),
            std::chrono::steady_clock::now()
        };
    }
    
    static void on_deallocation(void* ptr) {
        std::lock_guard<std::mutex> lock(mutex);
        allocations.erase(ptr);
    }
    
    static void report_leaks() {
        std::lock_guard<std::mutex> lock(mutex);
        for (const auto& [ptr, info] : allocations) {
            fprintf(stderr,
                "Memory leak detected:\n"
                "  Address: %p\n"
                "  Size: %zu bytes\n"
                "  Allocation time: %lld ms ago\n"
                "Stack trace:\n%s\n",
                ptr,
                info.size,
                std::chrono::duration_cast<
                    std::chrono::milliseconds>(
                    std::chrono::steady_clock::now() -
                    info.time).count(),
                info.stack_trace.c_str());
        }
    }
};
```

## 5.5 メモリリーク防止のガイドライン

### 1. コーディング規約
- RAIIパターンの使用
- スマートポインタの活用
- 所有権の明確化
- リソース管理の一貫性

### 2. デバッグ手法
- メモリリーク検出ツールの使用
- リソーストラッキングの活用
- スタックトレースの収集
- 定期的なメモリ使用量の監視

### 3. テスト戦略
- メモリリークテストの自動化
- エッジケースのテスト
- 長時間実行テスト
- リソース枯渇テスト

### 4. 運用対策
- メモリ使用量の監視
- リソース使用状況のログ
- アラート設定
- 定期的なメモリ解放
