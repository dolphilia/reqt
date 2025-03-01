# Qt特有のメモリ管理

## 3.1 親子関係の管理
```cpp
// 1. 親オブジェクトの設定
void set_parent_ownership(QWidget* child, QWidget* parent) {
    child->setParent(parent);  // 親が子の寿命を管理
}

// 2. 親子関係の解除
void clear_parent(QWidget* widget) {
    widget->setParent(nullptr);  // 親子関係の解除
}

// 3. 親子関係の確認
bool is_child_of(QWidget* child, QWidget* parent) {
    return child->parent() == parent;
}
```

## 3.2 Qtのスマートポインタ
```cpp
// 1. QScopedPointerの使用
QScopedPointer<QWidget> widget(new QWidget());
widget->show();  // スコープ終了時に自動削除

// 2. QSharedPointerの使用
QSharedPointer<QObject> obj = QSharedPointer<QObject>::create();
```

## 3.3 Qt特有のメモリ管理パターン

### 1. オブジェクト階層
```cpp
class WidgetHierarchy {
public:
    static void setup_hierarchy(QWidget* parent) {
        // 子ウィジェットの作成と親子関係の設定
        auto* child1 = new QWidget(parent);
        auto* child2 = new QWidget(parent);
        
        // 孫ウィジェットの作成
        auto* grandchild1 = new QWidget(child1);
        auto* grandchild2 = new QWidget(child2);
        
        // parentの削除時に全ての子孫が自動的に削除される
    }
    
    static void reparent(QWidget* widget, QWidget* new_parent) {
        // 親の変更（所有権の移転）
        widget->setParent(new_parent);
    }
    
    static void orphan(QWidget* widget) {
        // 親子関係の解除（所有権の解放）
        widget->setParent(nullptr);
        // この時点でwidgetの削除責任は呼び出し側に移る
    }
};
```

### 2. イベントフィルタ
```cpp
class EventFilter : public QObject {
public:
    bool eventFilter(QObject* watched, QEvent* event) override {
        // イベントのフィルタリング
        // watchedオブジェクトの寿命管理に注意
        return QObject::eventFilter(watched, event);
    }
};
```

## 3.4 メモリ管理の実装例

### 1. ウィジェット管理
```cpp
class WidgetManager {
    QWidget* parent_widget;
    std::vector<QWidget*> managed_widgets;
    
public:
    explicit WidgetManager(QWidget* parent)
        : parent_widget(parent) {}
    
    QWidget* create_widget() {
        auto* widget = new QWidget(parent_widget);
        managed_widgets.push_back(widget);
        return widget;
    }
    
    void remove_widget(QWidget* widget) {
        auto it = std::find(managed_widgets.begin(),
                          managed_widgets.end(), widget);
        if (it != managed_widgets.end()) {
            managed_widgets.erase(it);
            widget->deleteLater();  // 安全な削除
        }
    }
    
    ~WidgetManager() {
        // 明示的なクリーンアップは不要
        // 親ウィジェットの削除時に自動的に解放される
    }
};
```

### 2. リソース管理
```cpp
class ResourceManager {
    QObject* parent_object;
    QHash<QString, QObject*> resources;
    
public:
    explicit ResourceManager(QObject* parent)
        : parent_object(parent) {}
    
    void add_resource(const QString& key, QObject* resource) {
        resource->setParent(parent_object);  // 所有権の設定
        resources.insert(key, resource);
    }
    
    QObject* get_resource(const QString& key) {
        return resources.value(key);
    }
    
    void remove_resource(const QString& key) {
        if (auto* resource = resources.take(key)) {
            resource->setParent(nullptr);  // 所有権の解除
            resource->deleteLater();
        }
    }
};
```

## 3.5 メモリ管理のガイドライン

### 1. 親子関係の使用
- 適切な親オブジェクトの選択
- 所有権の明確な管理
- 循環参照の防止
- 親子関係の変更に注意

### 2. スマートポインタの選択
- QScopedPointerの積極的な使用
- QSharedPointerの適切な使用
- 生ポインタの最小限の使用
- 所有権の明確な表現

### 3. 削除タイミング
- deleteLater()の適切な使用
- イベントループとの連携
- 非同期削除の考慮
- 安全な解放の保証

### 4. デバッグとテスト
- 親子関係の検証
- メモリリークの検出
- 削除順序の確認
- 循環参照のチェック
