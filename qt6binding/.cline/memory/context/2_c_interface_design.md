# C言語インターフェース設計

## 2.1 関数命名規則
```c
// 基本パターン
[QtClass]_[operation]

// 例：
QWidget_create()      // コンストラクタ
QWidget_delete()      // デストラクタ
QWidget_show()        // メソッド
QWidget_setEnabled()  // プロパティ設定
```

## 2.2 型変換規則
```c
// オブジェクト参照
void* → 具体的なC++クラス*

// 文字列
const char* → QString (UTF-8)
QString → const char* (UTF-8)

// 数値型
int → enum class
bool → bool
```

## 2.3 戻り値規則
- 成功/失敗: bool型（true = 成功）
- オブジェクト作成: void*（NULL = 失敗）
- エラー状態: int型（0 = 成功、負値 = エラー）
- 文字列: const char*（NULL = エラー）
