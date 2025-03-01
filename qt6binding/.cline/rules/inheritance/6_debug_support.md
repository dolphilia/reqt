# デバッグサポート

## 6.1 継承関係の検証
```cpp
// 1. 継承チェーン検証
class InheritanceValidator {
public:
    static bool validateChain(void* obj) {
        auto* base = static_cast<BindQObject*>(obj);
        std::vector<std::string> chain;
        
        while (base) {
            chain.push_back(base->className());
            base = dynamic_cast<BindQObject*>(
                base->parent());
        }
        
        return validateChainIntegrity(chain);
    }

private:
    static bool validateChainIntegrity(
        const std::vector<std::string>& chain) {
        for (size_t i = 0; i < chain.size() - 1; ++i) {
            if (!TypeRegistry::isSubclassOf(
                chain[i], chain[i + 1])) {
                return false;
            }
        }
        return true;
    }
};

// 2. メモリレイアウト検証
class LayoutValidator {
public:
    static bool validateLayout(void* obj) {
        auto* base = static_cast<BindQObject*>(obj);
        
        // QObjectオフセットの検証
        auto* qobj = dynamic_cast<QObject*>(base);
        if (!qobj) return false;
        
        // QWidgetオフセットの検証
        if (auto* widget = dynamic_cast<QWidget*>(base)) {
            if (static_cast<void*>(qobj) !=
                static_cast<void*>(widget)) {
                return false;
            }
        }
        
        return true;
    }
};
```

## 6.2 継承関係のトレース
```cpp
// 1. 継承チェーンの出力
void dump_inheritance_chain(void* obj) {
    auto* base = static_cast<BindQObject*>(obj);
    std::vector<std::string> chain;
    
    while (base) {
        chain.push_back(base->className());
        base = dynamic_cast<BindQObject*>(
            base->parent());
    }
    
    qDebug() << "Inheritance chain:";
    for (const auto& type : chain) {
        qDebug() << " -" << type.c_str();
    }
}

// 2. 仮想関数テーブルの検証
class VTableValidator {
public:
    static bool validateVTable(void* obj) {
        auto* base = static_cast<BindQObject*>(obj);
        
        // 仮想関数の呼び出しテスト
        bool handle_valid = base->handle() != nullptr;
        bool classname_valid = base->className() != nullptr;
        
        // 派生クラス固有の仮想関数テスト
        if (auto* widget = dynamic_cast<QWidget*>(base)) {
            bool event_valid = widget->event(nullptr) == false;
            return handle_valid && classname_valid &&
                   event_valid;
        }
        
        return handle_valid && classname_valid;
    }
};
