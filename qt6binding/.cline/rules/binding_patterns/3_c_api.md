# C API実装パターン

## 3.1 基本構造
```cpp
// [QtClass]CAPI.cpp
extern "C" {
    // オブジェクト作成/削除
    void* [QtClass]_create(void* parent) {
        return new Bind[QtClass](reinterpret_cast<[QtClass]*>(parent));
    }

    void [QtClass]_delete(void* ptr) {
        delete static_cast<Bind[QtClass]*>(ptr);
    }

    // メソッド呼び出し
    void [QtClass]_someMethod(void* ptr) {
        static_cast<Bind[QtClass]*>(ptr)->someMethod();
    }

    // コールバック設定
    void [QtClass]_setSignalCallback(void* ptr, [QtClass]SignalCallback callback) {
        auto* obj = static_cast<Bind[QtClass]*>(ptr);
        [QtClass]Handler* handler = obj->handler();
        if (!handler) {
            handler = new [QtClass]Handler(obj);
            obj->setHandler(handler);
        }
        handler->setSignalCallback(callback);
    }
}
```

## 3.2 実装例
```cpp
// QTextEditCAPI.cpp
extern "C" {
    void* QTextEdit_create(void* parent) {
        return new BindQTextEdit(reinterpret_cast<QWidget*>(parent));
    }

    void QTextEdit_setText(void* text_edit, const char* text) {
        static_cast<BindQTextEdit*>(text_edit)->setText(
            QString::fromUtf8(text)
        );
    }

    void QTextEdit_setTextChangedCallback(
        void* text_edit,
        void (*callback)()
    ) {
        auto* edit = static_cast<BindQTextEdit*>(text_edit);
        TextEditHandler* handler = edit->handler();
        if (!handler) {
            handler = new TextEditHandler(edit);
            edit->setTextEditHandler(handler);
        }
        handler->setTextChangedCallback(callback);
    }
}
```

## 3.3 実装のポイント
1. 関数命名規則
   - クラス名とメソッド名をアンダースコアで区切る
   - 動詞で始まるメソッド名
   - get/setプレフィックスの使用

2. 型変換
   - void*からの適切なキャスト
   - 文字列のUTF-8変換
   - 数値型の変換

3. エラー処理
   - NULLポインタチェック
   - 例外のキャッチと変換
   - エラーコードの返却

4. メモリ管理
   - リソースの確保と解放
   - 親子関係の管理
   - 一時オブジェクトの処理
