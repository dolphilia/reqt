# エラー処理戦略

## 3.1 エラーの検出
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

## 3.2 エラーの伝播
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

## 3.3 エラー処理戦略のガイドライン

### 1. エラー検出の原則
- できるだけ早くエラーを検出する
- 適切なエラーコードを選択する
- 明確なエラーメッセージを提供する
- エラーの原因を特定しやすくする

### 2. エラー伝播の原則
- エラー情報を失わない
- 適切なクリーンアップを行う
- エラーチェーンを維持する
- デバッグ情報を保持する

### 3. エラー回復の原則
- 可能な場合は回復を試みる
- 安全な状態を維持する
- リソースを適切に解放する
- ユーザーに適切な情報を提供する

## 3.4 エラー処理の実装例

### 基本的なエラー処理
```cpp
ErrorCode basic_operation(void* ptr) {
    // 1. 引数の検証
    if (!validate_arguments(ptr, 0)) {
        return get_last_error();
    }

    // 2. 状態の検証
    auto* obj = static_cast<SomeClass*>(ptr);
    if (!validate_state(obj)) {
        return get_last_error();
    }

    // 3. 操作の実行
    try {
        if (!obj->perform_operation()) {
            set_last_error(ERROR_OPERATION, "Operation failed");
            return ERROR_OPERATION;
        }
    } catch (const std::exception& e) {
        set_last_error(ERROR_OPERATION, e.what());
        return ERROR_OPERATION;
    }

    return ERROR_NONE;
}
```

### 複雑な操作のエラー処理
```cpp
ErrorCode complex_operation(void* ptr) {
    // 1. リソースの確保
    ScopedResource res(acquire_resource());
    if (!res.get()) {
        return ERROR_MEMORY;
    }

    // 2. 初期化
    ErrorCode result = initialize_resource(res.get());
    if (result != ERROR_NONE) {
        return result;
    }

    // 3. 操作の実行
    result = process_resource(res.get());
    if (result != ERROR_NONE) {
        cleanup_resource(res.get());
        return result;
    }

    // 4. 結果の確認
    if (!validate_result(res.get())) {
        cleanup_resource(res.get());
        return ERROR_INVALID_RESULT;
    }

    return ERROR_NONE;
}
```

## 3.5 エラー処理のテスト

### エラーケースのテスト
```cpp
void test_error_handling() {
    // 1. NULL引数のテスト
    assert(basic_operation(NULL) == ERROR_NULL_POINTER);

    // 2. 無効な状態のテスト
    void* obj = create_invalid_object();
    assert(basic_operation(obj) == ERROR_INVALID_STATE);

    // 3. 操作失敗のテスト
    void* failing_obj = create_failing_object();
    assert(basic_operation(failing_obj) == ERROR_OPERATION);

    // 4. エラー情報の検証
    ErrorInfo info;
    collect_error_info(&info);
    assert(info.code == ERROR_OPERATION);
    assert(strcmp(info.message, "Operation failed") == 0);
}
