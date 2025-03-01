# エラー回復戦略

## 5.1 リソースのクリーンアップ
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

## 5.2 エラーからの復帰
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

## 5.3 エラー回復パターン

### 1. 段階的な回復
```cpp
ErrorCode recover_from_error(ErrorCode error) {
    switch (error) {
        case ERROR_MEMORY:
            // メモリの解放を試みる
            if (free_unused_memory()) {
                return ERROR_NONE;
            }
            break;
            
        case ERROR_NETWORK:
            // ネットワーク接続の再確立を試みる
            if (reconnect()) {
                return ERROR_NONE;
            }
            break;
            
        case ERROR_IO:
            // 代替パスでの再試行
            if (retry_with_alternative_path()) {
                return ERROR_NONE;
            }
            break;
    }
    
    return error;  // 回復失敗
}
```

### 2. 状態の復元
```cpp
class StateBackup {
    std::map<std::string, std::string> state;
public:
    void save(const char* key, const char* value) {
        state[key] = value;
    }
    
    const char* restore(const char* key) {
        auto it = state.find(key);
        return it != state.end() ? it->second.c_str() : nullptr;
    }
};

bool safe_operation() {
    StateBackup backup;
    
    // 状態のバックアップ
    backup.save("window_title", get_window_title());
    backup.save("window_size", get_window_size());
    
    try {
        // 操作の実行
        perform_risky_operation();
        return true;
    } catch (...) {
        // 状態の復元
        set_window_title(backup.restore("window_title"));
        set_window_size(backup.restore("window_size"));
        return false;
    }
}
```

## 5.4 回復戦略のガイドライン

### 1. リソース管理の原則
- RAIIパターンを積極的に使用する
- リソースの解放順序を考慮する
- 循環参照を避ける
- 部分的な解放を可能にする

### 2. エラー回復の原則
- できるだけ早く回復を試みる
- 段階的な回復戦略を用意する
- フォールバックメカニズムを実装する
- 回復不能な場合は適切に通知する

### 3. 状態管理の原則
- 重要な状態をバックアップする
- トランザクション的な処理を実装する
- ロールバックメカニズムを用意する
- 一貫性を保証する

## 5.5 回復処理の実装例

### 複雑な操作の回復処理
```cpp
ErrorCode complex_operation_with_recovery() {
    // 1. 状態のバックアップ
    StateBackup backup;
    save_current_state(&backup);
    
    // 2. 操作の実行
    ErrorCode result = perform_complex_operation();
    if (result != ERROR_NONE) {
        // 3. エラー回復の試行
        result = recover_from_error(result);
        if (result != ERROR_NONE) {
            // 4. 回復失敗時の状態復元
            restore_state(&backup);
        }
    }
    
    return result;
}
```

### リソース管理と回復
```cpp
class ManagedResource {
    void* ptr;
    StateBackup backup;
    bool valid;
    
public:
    explicit ManagedResource(void* p) : ptr(p), valid(true) {
        if (ptr) {
            // 初期状態のバックアップ
            backup_state();
        }
    }
    
    ~ManagedResource() {
        if (ptr) {
            if (!valid) {
                // 無効な状態の場合は復元を試みる
                restore_state();
            }
            cleanup_resource(ptr);
        }
    }
    
    bool perform_operation() {
        try {
            // 操作の実行
            do_operation(ptr);
            return true;
        } catch (...) {
            valid = false;
            return false;
        }
    }
    
private:
    void backup_state() {
        // 状態のバックアップ
        backup.save("state", get_state(ptr));
    }
    
    void restore_state() {
        // 状態の復元
        const char* state = backup.restore("state");
        if (state) {
            set_state(ptr, state);
        }
    }
};
