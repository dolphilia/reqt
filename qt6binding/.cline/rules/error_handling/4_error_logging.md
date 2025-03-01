# エラーのログ記録

## 4.1 エラーログの形式
```cpp
void log_error(const ErrorInfo* info) {
    fprintf(stderr, "Error[%d]: %s\n", info->code, info->message);
    fprintf(stderr, "  at %s:%d\n", info->file, info->line);
    fprintf(stderr, "  in function: %s\n", info->function);
}
```

## 4.2 エラーログレベル
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

## 4.3 ログ出力の実装

### ログフォーマッタ
```cpp
class LogFormatter {
public:
    static std::string format_error(const ErrorInfo* info) {
        std::stringstream ss;
        ss << "[ERROR] " << info->message << "\n"
           << "Code: " << info->code << "\n"
           << "File: " << info->file << ":" << info->line << "\n"
           << "Function: " << info->function;
        return ss.str();
    }

    static std::string format_warning(const char* message) {
        return std::string("[WARNING] ") + message;
    }

    static std::string format_info(const char* message) {
        return std::string("[INFO] ") + message;
    }

    static std::string format_debug(const char* message) {
        return std::string("[DEBUG] ") + message;
    }
};
```

### ログ出力先の管理
```cpp
class LogDestination {
public:
    virtual ~LogDestination() = default;
    virtual void write(const std::string& message) = 0;
};

class FileLogger : public LogDestination {
    FILE* file;
public:
    explicit FileLogger(const char* filename) {
        file = fopen(filename, "a");
    }
    ~FileLogger() {
        if (file) fclose(file);
    }
    void write(const std::string& message) override {
        if (file) {
            fprintf(file, "%s\n", message.c_str());
            fflush(file);
        }
    }
};

class ConsoleLogger : public LogDestination {
public:
    void write(const std::string& message) override {
        fprintf(stderr, "%s\n", message.c_str());
    }
};
```

## 4.4 ログ管理システム

### ログマネージャ
```cpp
class LogManager {
    static std::vector<std::unique_ptr<LogDestination>> destinations;
    static LogLevel current_level;
    static std::mutex mutex;

public:
    static void add_destination(std::unique_ptr<LogDestination> dest) {
        std::lock_guard<std::mutex> lock(mutex);
        destinations.push_back(std::move(dest));
    }

    static void set_level(LogLevel level) {
        std::lock_guard<std::mutex> lock(mutex);
        current_level = level;
    }

    static void log(LogLevel level, const std::string& message) {
        std::lock_guard<std::mutex> lock(mutex);
        if (level <= current_level) {
            for (const auto& dest : destinations) {
                dest->write(message);
            }
        }
    }

    static void log_error(const ErrorInfo* info) {
        log(LOG_LEVEL_ERROR, LogFormatter::format_error(info));
    }
};
```

### ログの使用例
```cpp
// ログ初期化
void initialize_logging() {
    LogManager::add_destination(
        std::make_unique<FileLogger>("error.log"));
    LogManager::add_destination(
        std::make_unique<ConsoleLogger>());
    LogManager::set_level(LOG_LEVEL_DEBUG);
}

// エラーログの記録
void handle_error(const ErrorInfo* info) {
    LogManager::log_error(info);
    // エラー処理
}

// 警告ログの記録
void report_warning(const char* message) {
    LogManager::log(LOG_LEVEL_WARNING,
        LogFormatter::format_warning(message));
}
```

## 4.5 ログ出力のガイドライン

### 1. ログレベルの使い分け
- ERROR: アプリケーションの動作に影響するエラー
- WARNING: 潜在的な問題や注意が必要な状況
- INFO: 重要な操作の成功や状態変更
- DEBUG: 開発時のデバッグ情報

### 2. ログメッセージの作成
- 明確で具体的な情報を含める
- タイムスタンプを付加する
- 関連する識別子を含める
- エラーの場合は原因と影響を記述する

### 3. ログ出力のパフォーマンス
- 不要なログを出力しない
- ログレベルによるフィルタリングを活用する
- バッファリングを適切に使用する
- ファイルI/Oの最適化を考慮する
