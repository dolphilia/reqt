# デバッグサポート

## 6.1 アサーション
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

## 6.2 エラートレース
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
```

## 6.3 デバッグ支援機能

### エラー情報の収集
```cpp
class ErrorCollector {
    std::vector<ErrorInfo> errors;
    bool collecting;

public:
    void start_collecting() {
        collecting = true;
        errors.clear();
    }

    void stop_collecting() {
        collecting = false;
    }

    void collect(const ErrorInfo& info) {
        if (collecting) {
            errors.push_back(info);
        }
    }

    const std::vector<ErrorInfo>& get_errors() const {
        return errors;
    }

    void clear() {
        errors.clear();
    }
};
```

### エラー状態の監視
```cpp
class ErrorMonitor {
    std::unordered_map<std::string, int> error_counts;
    std::mutex mutex;

public:
    void record_error(const char* type) {
        std::lock_guard<std::mutex> lock(mutex);
        ++error_counts[type];
    }

    void print_statistics() {
        std::lock_guard<std::mutex> lock(mutex);
        for (const auto& [type, count] : error_counts) {
            printf("Error type '%s': %d occurrences\n",
                   type.c_str(), count);
        }
    }

    bool has_exceeded_threshold(const char* type,
                              int threshold) {
        std::lock_guard<std::mutex> lock(mutex);
        return error_counts[type] > threshold;
    }
};
```

## 6.4 デバッグ用ユーティリティ

### エラー状態のダンプ
```cpp
class ErrorDumper {
public:
    static void dump_error_info(const ErrorInfo* info) {
        printf("=== Error Information ===\n");
        printf("Code: %d\n", info->code);
        printf("Message: %s\n", info->message);
        printf("Location: %s:%d\n", info->file, info->line);
        printf("Function: %s\n", info->function);
        printf("=======================\n");
    }

    static void dump_error_stack() {
        printf("=== Error Stack ===\n");
        ErrorTracer::dump();
        printf("==================\n");
    }

    static void dump_error_statistics() {
        printf("=== Error Statistics ===\n");
        ErrorMonitor monitor;
        monitor.print_statistics();
        printf("======================\n");
    }
};
```

### デバッグログ
```cpp
class DebugLogger {
    static bool enabled;
    static LogLevel min_level;

public:
    static void enable(bool enable = true) {
        enabled = enable;
    }

    static void set_min_level(LogLevel level) {
        min_level = level;
    }

    static void log(LogLevel level, const char* format, ...) {
        if (!enabled || level < min_level) return;

        va_list args;
        va_start(args, format);
        vprintf(format, args);
        va_end(args);
        printf("\n");
    }

    static void log_error(const ErrorInfo* info) {
        if (!enabled || LOG_LEVEL_ERROR < min_level) return;
        ErrorDumper::dump_error_info(info);
    }
};
```

## 6.5 デバッグ支援のガイドライン

### 1. アサーションの使用
- 重要な前提条件の検証
- 不変条件の確認
- 戻り値の検証
- メモリ状態の確認

### 2. エラートレースの活用
- エラーの発生順序の記録
- エラーチェーンの追跡
- エラーの原因分析
- デバッグ情報の収集

### 3. デバッグログの管理
- 適切なログレベルの設定
- 必要な情報の選択
- パフォーマンスへの配慮
- セキュリティ情報の保護

### 4. デバッグツールの使用
- メモリチェッカー
- プロファイラ
- 静的解析ツール
- デバッガ
