# メモリ管理

## 5.1 所有権の管理
```cpp
// 1. 親子関係の管理
void set_parent_ownership(void* child, void* parent) {
    if (auto* c = safe_cast<BindQObject>(child)) {
        c->setParent(parent);
    }
}

// 2. 自動削除の管理
class AutoDeleteHandler : public QObject {
public:
    explicit AutoDeleteHandler(QObject* target)
        : m_target(target) {
        target->setParent(this);
    }
    
    ~AutoDeleteHandler() {
        delete m_target;
    }

private:
    QObject* m_target;
};
```

## 5.2 リソースの解放
```cpp
// 1. 階層的な解放
void delete_widget_hierarchy(void* widget) {
    if (auto* w = safe_cast<BindQWidget>(widget)) {
        // 子ウィジェットは自動的に削除される
        delete w;
    }
}

// 2. 参照カウントの管理
class RefCountedWidget : public BindQWidget {
    std::atomic<int> ref_count{1};
public:
    void addRef() {
        ref_count.fetch_add(1, std::memory_order_relaxed);
    }
    
    void release() {
        if (ref_count.fetch_sub(1,
            std::memory_order_acq_rel) == 1) {
            delete this;
        }
    }
};
