# エラーコード体系

## 1.1 基本エラーコード
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

## 1.2 エラー情報構造体
```c
typedef struct {
    ErrorCode code;          // エラーコード
    const char* message;     // エラーメッセージ
    const char* file;        // エラー発生ファイル
    int line;               // エラー発生行
    const char* function;    // エラー発生関数
} ErrorInfo;
```

## 1.3 エラーコードの使用ガイドライン

### エラーコードの選択
1. 適切なエラーコードの選択
   - NULL_POINTERは引数検証で使用
   - INVALID_ARGUMENTは値の範囲チェックで使用
   - MEMORYはメモリ確保失敗時に使用
   - OPERATIONは操作失敗時に使用

2. エラーコードの組み合わせ
   - 複数のエラーが発生した場合は最も重要なものを返す
   - エラーの詳細はエラー情報構造体に格納

### エラーメッセージの作成
1. メッセージの形式
   - 簡潔で明確な説明
   - エラーの原因を含める
   - 可能な場合は解決策を示唆

2. メッセージの例
```c
// 良い例
"NULL pointer provided for widget parameter"
"Value 101 exceeds maximum allowed value of 100"

// 悪い例
"Error occurred"  // 具体性に欠ける
"Bad input"      // 情報が不足
```

## 1.4 エラー情報の設定

### エラー情報の設定関数
```c
void set_error(ErrorInfo* info, ErrorCode code, const char* message) {
    if (info) {
        info->code = code;
        info->message = message;
        info->file = __FILE__;
        info->line = __LINE__;
        info->function = __func__;
    }
}
```

### エラー情報の使用例
```c
ErrorInfo error_info;
void* ptr = some_operation();
if (!ptr) {
    set_error(&error_info, ERROR_MEMORY,
              "Failed to allocate memory for widget");
    return NULL;
}
