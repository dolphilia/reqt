# 型変換と検証

## 2.1 ダウンキャスト
```cpp
// 1. 安全なダウンキャスト
template<typename T>
T* safe_cast(void* ptr) {
    if (!ptr) return nullptr;
    
    auto* obj = static_cast<BindQObject*>(ptr);
    if (auto* cast = dynamic_cast<T*>(obj)) {
        return cast;
    }
    return nullptr;
}

// 2. 型チェック
bool is_type(void* ptr, const char* type) {
    if (!ptr) return false;
    
    auto* obj = static_cast<BindQObject*>(ptr);
    return strcmp(obj->className(), type) == 0;
}
```

## 2.2 型情報の管理
```cpp
// 1. 型情報レジストリ
class TypeRegistry {
    static std::unordered_map<std::string,
                             std::vector<std::string>> inheritance_map;
public:
    static void registerInheritance(const std::string& derived,
                                  const std::string& base) {
        inheritance_map[derived].push_back(base);
    }
    
    static bool isSubclassOf(const std::string& derived,
                            const std::string& base) {
        auto it = inheritance_map.find(derived);
        if (it == inheritance_map.end()) return false;
        
        const auto& bases = it->second;
        return std::find(bases.begin(), bases.end(),
                        base) != bases.end();
    }
};

// 2. 型情報の登録
void register_types() {
    TypeRegistry::registerInheritance("QPushButton",
                                    "QAbstractButton");
    TypeRegistry::registerInheritance("QAbstractButton",
                                    "QWidget");
    TypeRegistry::registerInheritance("QWidget",
                                    "QObject");
}
