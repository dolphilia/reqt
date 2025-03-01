# エラー処理パターン

## 2.1 C++側の実装
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

## 2.2 C APIの実装
```cpp
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

## 2.3 エラー処理のベストプラクティス

### 早期リターン
```cpp
ErrorCode process_widget(void* widget) {
    // 引数の検証
    if (!widget) {
        return ERROR_NULL_POINTER;
    }

    // 型変換と状態チェック
    auto* w = static_cast<QWidget*>(widget);
    if (!w->isVisible()) {
        return ERROR_INVALID_STATE;
    }

    // メイン処理
    if (!w->update()) {
        return ERROR_OPERATION;
    }

    return ERROR_NONE;
}
```

### エラーの伝播
```cpp
ErrorCode complex_operation(void* widget) {
    // 第1ステップ
    ErrorCode error = step1(widget);
    if (error != ERROR_NONE) {
        return error;  // エラーを上位に伝播
    }

    // 第2ステップ
    error = step2(widget);
    if (error != ERROR_NONE) {
        cleanup_step1(widget);  // 部分的なクリーンアップ
        return error;
    }

    return ERROR_NONE;
}
```

### リソースの保護
```cpp
class ScopedResource {
    void* ptr;
public:
    explicit ScopedResource(void* p) : ptr(p) {}
    ~ScopedResource() {
        if (ptr) cleanup(ptr);
    }
    void* get() const { return ptr; }
    void* release() {
        void* p = ptr;
        ptr = nullptr;
        return p;
    }
private:
    ScopedResource(const ScopedResource&) = delete;
    ScopedResource& operator=(const ScopedResource&) = delete;
};

ErrorCode safe_operation() {
    ScopedResource res(acquire_resource());
    // 操作の実行
    // 例外が発生してもリソースは自動的に解放される
    return ERROR_NONE;
}
```

## 2.4 エラー処理のアンチパターン

### 避けるべきパターン
```cpp
// 1. エラーの無視
void bad_example1(void* ptr) {
    static_cast<QWidget*>(ptr)->show();  // エラーチェックなし
}

// 2. 過剰なネスト
ErrorCode bad_example2(void* ptr) {
    if (ptr) {
        if (is_valid(ptr)) {
            if (is_ready(ptr)) {
                // 処理
            } else {
                return ERROR_NOT_READY;
            }
        } else {
            return ERROR_INVALID;
        }
    } else {
        return ERROR_NULL_POINTER;
    }
    return ERROR_NONE;
}

// 3. 不適切な例外処理
void bad_example3(void* ptr) {
    try {
        // 処理
    } catch (...) {
        // エラーを無視
    }
}
```

### 推奨パターン
```cpp
// 1. 適切なエラーチェック
void good_example1(void* ptr) {
    if (!ptr) return;
    auto* widget = static_cast<QWidget*>(ptr);
    if (!widget->isVisible()) return;
    widget->show();
}

// 2. フラット構造
ErrorCode good_example2(void* ptr) {
    if (!ptr) return ERROR_NULL_POINTER;
    if (!is_valid(ptr)) return ERROR_INVALID;
    if (!is_ready(ptr)) return ERROR_NOT_READY;
    
    // 処理
    return ERROR_NONE;
}

// 3. 適切な例外処理
void good_example3(void* ptr) {
    try {
        // 処理
    } catch (const std::exception& e) {
        // エラーを適切に処理
        log_error(e.what());
        cleanup();
    }
}
