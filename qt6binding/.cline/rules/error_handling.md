# エラー処理ガイドライン

## 1. エラーコード体系

### 1.1 基本エラーコード
```c
typedef enum {
    ERROR_NONE = 0,
    ERROR_NULL_POINTER = -1,
    ERROR_INVALID_ARGUMENT = -2,
    ERROR_MEMORY = -3,
    ERROR_OPERATION = -4,
    ERROR_NOT_INITIALIZED = -5,
    ERROR_ALREADY_EXISTS = -6,
    ERROR_NOT_FOUND = -7,
    ERROR_PERMISSION = -8,
    ERROR_TIMEOUT = -9,
    ERROR_OVERFLOW = -10,
    ERROR_UNDERFLOW = -11,
    ERROR_DIVISION_BY_ZERO = -12,
    ERROR_INVALID_STATE = -13,
    ERROR_IO = -14,
    ERROR_NETWORK = -15,
    ERROR_PROTOCOL = -16,
    ERROR_FORMAT = -17,
    ERROR_SYNTAX = -18,
    ERROR_LOGIC = -19,
    ERROR_SYSTEM = -20
} ErrorCode;
```

### 1.2 エラー情報構造体
```c
typedef struct {
    ErrorCode code;          // エラーコード
    const char* message;     // エラーメッセージ
    const char* file;        // エラー発生ファイル
    int line;               // エラー発生行
    const char* function;    // エラー発生関数
} ErrorInfo;
```

## 2. エラー処理パターン

### 2.1 C++側の実装
```cpp
// Result型の定義
struct Result {
    bool success;
    const char* error_message;
    void* data;
};

// エラー処理を含む操作の実装
Result handle_operation(void* ptr) {
    try {
        // NULLポインタチェック
        if (!ptr) {
            return {false, "Null pointer", nullptr};
        }

        // 型変換と有効性チェック
        auto* obj = static_cast<SomeClass*>(ptr);
        if (!obj->isValid()) {
            return {false, "Invalid object state", nullptr};
        }

        // 操作の実行
        void* result = obj->doSomething();
        return {true, nullptr, result};

    } catch (const std::bad_alloc& e) {
        return {false, "Memory allocation failed", nullptr};
    } catch (const std::invalid_argument& e) {
        return {false, e.what(), nullptr};
    } catch (const std::exception& e) {
        return {false, e.what(), nullptr};
    } catch (...) {
        return {false, "Unknown error occurred", nullptr};
    }
}
```

### 2.2 C APIの実装
```c
// エラー情報の設定
void set_error(ErrorInfo* info, ErrorCode code, const char* message) {
    if (info) {
        info->code = code;
        info->message = message;
        info->file = __FILE__;
        info->line = __LINE__;
        info->function = __func__;
    }
}

// C API関数の実装
ErrorCode operation(void* ptr, void** result) {
    Result cpp_result = handle_operation(ptr);
    
    if (!cpp_result.success) {
        set_last_error(ERROR_OPERATION, cpp_result.error_message);
        return ERROR_OPERATION;
    }
    
    *result = cpp_result.data;
    return ERROR_NONE;
}
```

## 3. エラー処理戦略

### 3.1 エラーの検出
```cpp
// 1. 引数の検証
bool validate_arguments(void* ptr, int value) {
    if (!ptr) {
        set_last_error(ERROR_NULL_POINTER, "Null pointer provided");
        return false;
    }
    if (value < 0 || value > 100) {
        set_last_error(ERROR_INVALID_ARGUMENT, "Value out of range");
        return false;
    }
    return true;
}

// 2. 状態の検証
bool validate_state(SomeClass* obj) {
    if (!obj->isInitialized()) {
        set_last_error(ERROR_NOT_INITIALIZED, "Object not initialized");
        return false;
    }
    if (obj->isLocked()) {
        set_last_error(ERROR_INVALID_STATE, "Object is locked");
        return false;
    }
    return true;
}
```

### 3.2 エラーの伝播
```cpp
// 1. エラーチェーンの作成
ErrorCode process_operation(void* ptr) {
    // 最初の操作
    ErrorCode result = first_operation(ptr);
    if (result != ERROR_NONE) {
        return result;
    }
    
    // 次の操作
    result = second_operation(ptr);
    if (result != ERROR_NONE) {
        return result;
    }
    
    return ERROR_NONE;
}

// 2. エラー情報の収集
void collect_error_info(ErrorInfo* info) {
    ErrorCode code = get_last_error();
    const char* message = get_error_message();
    set_error(info, code, message);
}
```

## 4. エラーのログ記録

### 4.1 エラーログの形式
```cpp
void log_error(const ErrorInfo* info) {
    fprintf(stderr, "Error[%d]: %s\n", info->code, info->message);
    fprintf(stderr, "  at %s:%d\n", info->file, info->line);
    fprintf(stderr, "  in function: %s\n", info->function);
}
```

### 4.2 エラーログレベル
```cpp
typedef enum {
    LOG_LEVEL_ERROR,    // 重大なエラー
    LOG_LEVEL_WARNING,  // 警告
    LOG_LEVEL_INFO,     // 情報
    LOG_LEVEL_DEBUG     // デバッグ情報
} LogLevel;

void log_message(LogLevel level, const char* format, ...) {
    va_list args;
    va_start(args, format);
    // ログ出力の実装
    va_end(args);
}
```

## 5. エラー回復戦略

### 5.1 リソースのクリーンアップ
```cpp
// 1. RAII パターン
class ScopedResource {
    void* ptr;
public:
    explicit ScopedResource(void* p) : ptr(p) {}
    ~ScopedResource() {
        if (ptr) {
            cleanup_resource(ptr);
        }
    }
};

// 2. トランザクション的な処理
bool atomic_operation() {
    // バックアップの作成
    backup();
    
    try {
        // 操作の実行
        perform_operation();
        return true;
    } catch (...) {
        // エラー時は復元
        restore();
        return false;
    }
}
```

### 5.2 エラーからの復帰
```cpp
// 1. 再試行メカニズム
bool retry_operation(int max_attempts) {
    for (int i = 0; i < max_attempts; i++) {
        if (perform_operation()) {
            return true;
        }
        // 待機してから再試行
        sleep_milliseconds(100 * (i + 1));
    }
    return false;
}

// 2. フォールバック処理
void* get_resource(const char* primary_path) {
    void* resource = try_primary_path(primary_path);
    if (!resource) {
        resource = try_fallback_path(get_fallback_path());
    }
    return resource;
}
```

## 6. デバッグサポート

### 6.1 アサーション
```c
#ifdef DEBUG
#define ASSERT(condition, message) \
    do { \
        if (!(condition)) { \
            log_message(LOG_LEVEL_ERROR, \
                "Assertion failed: %s\n" \
                "File: %s\n" \
                "Line: %d\n" \
                "Message: %s", \
                #condition, __FILE__, __LINE__, message); \
            abort(); \
        } \
    } while (0)
#else
#define ASSERT(condition, message) ((void)0)
#endif
```

### 6.2 エラートレース
```cpp
class ErrorTracer {
    static std::vector<ErrorInfo> error_stack;
public:
    static void push(const ErrorInfo& info) {
        error_stack.push_back(info);
    }
    
    static void dump() {
        for (const auto& error : error_stack) {
            log_error(&error);
        }
    }
};
