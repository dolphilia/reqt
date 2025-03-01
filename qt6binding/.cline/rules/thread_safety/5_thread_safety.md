# スレッド安全性

## 5.1 スレッドセーフなシグナル処理
```cpp
// 1. スレッドセーフなコールバック呼び出し
void invoke_callback_safe(QObject* sender, void* callback,
                        void* data) {
    if (QThread::currentThread() == sender->thread()) {
        // 同じスレッドなら直接呼び出し
        reinterpret_cast<void (*)(void*, void*)>(callback)(
            sender, data);
    } else {
        // 異なるスレッドならキューイング
        QMetaObject::invokeMethod(sender, [=]() {
            reinterpret_cast<void (*)(void*, void*)>(callback)(
                sender, data);
        }, Qt::QueuedConnection);
    }
}

// 2. スレッドセーフなイベント処理
class ThreadSafeHandler : public QObject {
    Q_OBJECT
    std::mutex mutex;
    std::queue<std::function<void()>> eventQueue;

public slots:
    void processEvents() {
        std::lock_guard<std::mutex> lock(mutex);
        while (!eventQueue.empty()) {
            eventQueue.front()();
            eventQueue.pop();
        }
    }

public:
    void postEvent(std::function<void()> event) {
        std::lock_guard<std::mutex> lock(mutex);
        eventQueue.push(std::move(event));
        QMetaObject::invokeMethod(this, "processEvents",
                                Qt::QueuedConnection);
    }
};
```

## 5.2 スレッドセーフなデータ管理

### 1. スレッドセーフなコールバック管理
```cpp
class ThreadSafeCallbackManager {
    std::unordered_map<std::string, void*> callbacks;
    std::mutex mutex;
    
public:
    void setCallback(const std::string& signal, void* callback) {
        std::lock_guard<std::mutex> lock(mutex);
        callbacks[signal] = callback;
    }
    
    void* getCallback(const std::string& signal) {
        std::lock_guard<std::mutex> lock(mutex);
        auto it = callbacks.find(signal);
        return (it != callbacks.end()) ? it->second : nullptr;
    }
    
    void removeCallback(const std::string& signal) {
        std::lock_guard<std::mutex> lock(mutex);
        callbacks.erase(signal);
    }
};
```

### 2. スレッドセーフなリソース管理
```cpp
class ThreadSafeResourceManager {
    std::unordered_map<void*, std::unique_ptr<QObject>> resources;
    std::mutex mutex;
    
public:
    void addResource(void* key, std::unique_ptr<QObject> resource) {
        std::lock_guard<std::mutex> lock(mutex);
        resources[key] = std::move(resource);
    }
    
    QObject* getResource(void* key) {
        std::lock_guard<std::mutex> lock(mutex);
        auto it = resources.find(key);
        return (it != resources.end()) ? it->second.get() : nullptr;
    }
    
    void removeResource(void* key) {
        std::lock_guard<std::mutex> lock(mutex);
        resources.erase(key);
    }
};
```

## 5.3 スレッドセーフな実装パターン

### 1. スレッドローカルストレージ
```cpp
class ThreadLocalStorage {
    static thread_local std::unordered_map<std::string, void*> storage;
    
public:
    static void setValue(const std::string& key, void* value) {
        storage[key] = value;
    }
    
    static void* getValue(const std::string& key) {
        auto it = storage.find(key);
        return (it != storage.end()) ? it->second : nullptr;
    }
    
    static void removeValue(const std::string& key) {
        storage.erase(key);
    }
};
```

### 2. ロックフリーデータ構造
```cpp
template<typename T>
class LockFreeQueue {
    struct Node {
        T data;
        std::atomic<Node*> next;
    };
    
    std::atomic<Node*> head;
    std::atomic<Node*> tail;
    
public:
    void push(T value) {
        Node* node = new Node{value, nullptr};
        Node* oldTail = tail.load();
        
        while (!tail.compare_exchange_weak(oldTail, node)) {
            oldTail = tail.load();
        }
        
        oldTail->next = node;
    }
    
    bool pop(T& value) {
        Node* oldHead = head.load();
        Node* newHead;
        
        do {
            if (!oldHead) return false;
            newHead = oldHead->next;
        } while (!head.compare_exchange_weak(oldHead, newHead));
        
        value = oldHead->data;
        delete oldHead;
        return true;
    }
};
```

## 5.4 スレッド安全性の実装例

### 1. スレッドセーフなシグナルハンドラ
```cpp
class ThreadSafeSignalHandler : public QObject {
    Q_OBJECT
    std::mutex callbackMutex;
    std::unordered_map<std::string, void*> callbacks;
    
public:
    void setCallback(const std::string& signal, void* callback) {
        std::lock_guard<std::mutex> lock(callbackMutex);
        callbacks[signal] = callback;
    }
    
private slots:
    void handleSignal() {
        std::lock_guard<std::mutex> lock(callbackMutex);
        auto it = callbacks.find("signal");
        if (it != callbacks.end()) {
            reinterpret_cast<void (*)(void*)>(it->second)(this);
        }
    }
};
```

### 2. スレッドセーフなイベントディスパッチャ
```cpp
class ThreadSafeEventDispatcher {
    std::mutex mutex;
    std::condition_variable cv;
    std::queue<std::function<void()>> events;
    bool running;
    std::thread worker;
    
public:
    ThreadSafeEventDispatcher() : running(true) {
        worker = std::thread([this]() {
            processEvents();
        });
    }
    
    ~ThreadSafeEventDispatcher() {
        {
            std::lock_guard<std::mutex> lock(mutex);
            running = false;
        }
        cv.notify_one();
        worker.join();
    }
    
    void postEvent(std::function<void()> event) {
        std::lock_guard<std::mutex> lock(mutex);
        events.push(std::move(event));
        cv.notify_one();
    }
    
private:
    void processEvents() {
        while (true) {
            std::function<void()> event;
            {
                std::unique_lock<std::mutex> lock(mutex);
                cv.wait(lock, [this]() {
                    return !running || !events.empty();
                });
                
                if (!running && events.empty()) {
                    break;
                }
                
                event = std::move(events.front());
                events.pop();
            }
            event();
        }
    }
};
```

## 5.5 スレッド安全性のガイドライン

### 1. 基本原則
- データ競合の防止
- デッドロックの回避
- メモリバリアの適切な使用
- スレッドの同期制御

### 2. 実装方針
- ロックの最小化
- アトミック操作の活用
- スレッドローカルの利用
- イベントループの活用

### 3. パフォーマンス考慮
- ロックの粒度の最適化
- 待機時間の最小化
- キャッシュラインの考慮
- スレッド数の適正化

### 4. デバッグ支援
- デッドロックの検出
- 競合状態の検出
- パフォーマンスの計測
- ログの記録
