# データ変換

## 4.1 基本型の変換
```cpp
// 1. C++からCへの変換
void convert_to_c(const QVariant& value, void* data) {
    switch (value.type()) {
        case QVariant::Bool:
            *static_cast<bool*>(data) = value.toBool();
            break;
        case QVariant::Int:
            *static_cast<int*>(data) = value.toInt();
            break;
        case QVariant::String: {
            auto str = value.toString().toUtf8();
            strncpy(static_cast<char*>(data), str.constData(),
                   str.size() + 1);
            break;
        }
    }
}

// 2. CからC++への変換
QVariant convert_from_c(void* data, int type) {
    switch (type) {
        case BOOL_TYPE:
            return QVariant(*static_cast<bool*>(data));
        case INT_TYPE:
            return QVariant(*static_cast<int*>(data));
        case STRING_TYPE:
            return QVariant(QString::fromUtf8(
                static_cast<char*>(data)));
        default:
            return QVariant();
    }
}
```

## 4.2 複合型の変換
```cpp
// 1. 構造体の変換
struct Point {
    int x;
    int y;
};

void convert_point(const QPoint& qpoint, Point* point) {
    point->x = qpoint.x();
    point->y = qpoint.y();
}

QPoint convert_point(const Point* point) {
    return QPoint(point->x, point->y);
}

// 2. 配列の変換
struct Array {
    void** items;
    int count;
};

void convert_list(const QList<QObject*>& list, Array* array) {
    array->count = list.size();
    array->items = new void*[array->count];
    for (int i = 0; i < array->count; ++i) {
        array->items[i] = list[i];
    }
}
```

## 4.3 データ変換パターン

### 1. 値型の変換
```cpp
class ValueConverter {
public:
    // 基本型の変換
    template<typename T>
    static T convert_value(void* data) {
        return *static_cast<T*>(data);
    }
    
    // 列挙型の変換
    template<typename EnumType>
    static EnumType convert_enum(int value) {
        return static_cast<EnumType>(value);
    }
    
    // フラグの変換
    template<typename FlagType>
    static FlagType convert_flags(unsigned int flags) {
        return static_cast<FlagType>(flags);
    }
};
```

### 2. オブジェクト型の変換
```cpp
class ObjectConverter {
public:
    // ポインタの変換
    template<typename T>
    static T* convert_pointer(void* ptr) {
        return static_cast<T*>(ptr);
    }
    
    // スマートポインタの変換
    template<typename T>
    static QSharedPointer<T> convert_to_shared(void* ptr) {
        return QSharedPointer<T>(static_cast<T*>(ptr));
    }
    
    // 所有権の移転
    template<typename T>
    static T* take_ownership(void* ptr) {
        auto* obj = static_cast<T*>(ptr);
        obj->setParent(nullptr);
        return obj;
    }
};
```

## 4.4 データ変換の実装例

### 1. シグナルパラメータの変換
```cpp
class SignalParameterConverter {
public:
    // 単一パラメータの変換
    template<typename T>
    static void convert_parameter(void* src, void* dst) {
        *static_cast<T*>(dst) = *static_cast<T*>(src);
    }
    
    // 複数パラメータの変換
    template<typename... Args>
    static void convert_parameters(void* src,
                                 std::tuple<Args...>& dst) {
        // パラメータタプルの変換
    }
    
    // パラメータパックの変換
    static void convert_parameter_pack(void* src,
                                     void** dst,
                                     int count) {
        std::memcpy(dst, src, count * sizeof(void*));
    }
};
```

### 2. コールバックパラメータの変換
```cpp
class CallbackParameterConverter {
public:
    // コールバックデータの変換
    template<typename T>
    static void convert_callback_data(void* src,
                                    void (*callback)(void*, T)) {
        callback(src, *static_cast<T*>(src));
    }
    
    // コールバック結果の変換
    template<typename R>
    static R convert_callback_result(void* result) {
        return *static_cast<R*>(result);
    }
    
    // エラー状態の変換
    static bool convert_error_state(void* error) {
        return static_cast<bool>(error);
    }
};
```

## 4.5 データ変換のガイドライン

### 1. 型安全性
- 型チェックの実施
- キャストの安全性確保
- エラー処理の追加
- 境界チェックの実装

### 2. メモリ管理
- バッファサイズの確認
- メモリリークの防止
- 一時バッファの管理
- クリーンアップの保証

### 3. パフォーマンス
- 不要なコピーの回避
- バッファの再利用
- キャッシュの活用
- 最適化の検討

### 4. エラー処理
- 変換エラーの検出
- エラー状態の伝播
- リカバリ処理の実装
- デバッグ情報の提供
