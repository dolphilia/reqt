# Qt6バインディング 設計コンテキスト

## 1. バインディングの基本方針

### 1.1 設計原則
- 安全性: メモリ管理とエラー処理の厳格な実装
- 一貫性: 統一された命名規則とAPI設計
- 使いやすさ: C言語開発者にとって自然なインターフェース
- 保守性: 明確な実装パターンと十分なドキュメント

### 1.2 アーキテクチャ層
1. C++レイヤー（Qt6クラス）
2. バインディングレイヤー（Bindクラス）
3. イベントレイヤー（Handlerクラス）
4. C APIレイヤー（CAPI実装）

## 2. C言語インターフェース設計

### 2.1 関数命名規則
```c
// 基本パターン
[QtClass]_[operation]

// 例：
QWidget_create()      // コンストラクタ
QWidget_delete()      // デストラクタ
QWidget_show()        // メソッド
QWidget_setEnabled()  // プロパティ設定
```

### 2.2 型変換規則
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

### 2.3 戻り値規則
- 成功/失敗: bool型（true = 成功）
- オブジェクト作成: void*（NULL = 失敗）
- エラー状態: int型（0 = 成功、負値 = エラー）
- 文字列: const char*（NULL = エラー）

## 3. メモリ管理方針

### 3.1 オブジェクトの寿命
```c
// 1. 明示的な作成と削除
void* obj = QWidget_create(NULL);
QWidget_delete(obj);

// 2. 親子関係による自動削除
void* parent = QWidget_create(NULL);
void* child = QWidget_create(parent);
QWidget_delete(parent);  // childは自動削除
```

### 3.2 リソース管理規則
1. create/deleteの対応を必須とする
2. 親オブジェクトの削除で子を自動削除
3. 一時リソースは関数内で解放
4. メモリリークの定期的な確認

### 3.3 文字列管理
```c
// 1. 文字列の取得
const char* text = QWidget_windowTitle(widget);
// 注: 次のAPI呼び出しまで有効

// 2. 文字列の設定
QWidget_setWindowTitle(widget, "Title");
// 注: 関数内でコピーを作成
```

## 4. エラー処理方針

### 4.1 エラー検出
```c
// 1. NULLチェック
void* widget = QWidget_create(NULL);
if (!widget) {
    // エラー処理
}

// 2. 戻り値チェック
int result = QWidget_someOperation(widget);
if (result < 0) {
    // エラー処理
}
```

### 4.2 エラー通知
1. エラーコードの返却
2. エラーメッセージの設定
3. コールバックによる通知
4. ログ出力

### 4.3 例外処理
```cpp
// C++側
try {
    // Qt操作
} catch (const std::exception& e) {
    // エラー状態に変換
    return NULL;  // または エラーコード
}

// C側
if (error_occurred) {
    // クリーンアップと回復処理
}
```

## 5. シグナル/スロット処理

### 5.1 コールバック定義
```c
// 1. コールバック関数型
typedef void (*ButtonClickCallback)(void* button);

// 2. コールバック設定
void QPushButton_setClickCallback(
    void* button,
    ButtonClickCallback callback
);
```

### 5.2 イベント処理フロー
1. Qt シグナル発生
2. Handler クラスがシグナルを受信
3. 登録されたコールバックを呼び出し
4. C言語側で処理を実行

## 6. スレッド安全性

### 6.1 基本原則
- メインスレッドでのGUI操作
- スレッドセーフなリソース管理
- 排他制御の実装

### 6.2 実装方針
1. スレッド間通信の制御
2. リソースの適切なロック
3. スレッドセーフなコールバック
4. デッドロック防止

## 7. パフォーマンス考慮

### 7.1 最適化方針
1. 不要なコピーの削減
2. メモリアロケーションの最小化
3. キャッシュの活用
4. 効率的な型変換

### 7.2 監視項目
- メモリ使用量
- CPU使用率
- レスポンス時間
- リソース解放の遅延
