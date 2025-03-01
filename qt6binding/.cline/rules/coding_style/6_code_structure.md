# コード構造

## 6.1 クラス構造
```cpp
class ClassName {
public:
    // 1. コンストラクタ/デストラクタ
    ClassName();
    ~ClassName();
    
    // 2. パブリックメソッド
    void publicMethod();
    
    // 3. パブリックスロット
    public slots:
    void onSomething();
    
    // 4. シグナル
    signals:
    void somethingHappened();
    
protected:
    // 5. 保護メソッド
    virtual void protectedMethod();
    
    // 6. 保護メンバ
    int m_protectedValue;
    
private:
    // 7. プライベートメソッド
    void privateMethod();
    
    // 8. プライベートメンバ
    int m_privateValue;
};
```

## 6.2 メソッド構造
```cpp
ReturnType ClassName::methodName(ParamType param) {
    // 1. 引数の検証
    if (!param) {
        return error;
    }

    // 2. 前処理
    prepare();

    // 3. メイン処理
    ReturnType result = process(param);

    // 4. 後処理
    cleanup();

    // 5. 結果返却
    return result;
}
```

## 6.3 バインディング固有の構造

### Bindクラス
```cpp
class BindQWidget : public QWidget {
public:
    // 1. コンストラクタ/デストラクタ
    explicit BindQWidget(QWidget* parent = nullptr);
    ~BindQWidget();

    // 2. Qt機能のラッパー
    void setWindowTitle(const QString& title);
    QString windowTitle() const;

    // 3. ハンドラ管理
    void setHandler(QWidgetHandler* handler);
    QWidgetHandler* handler() const;

private:
    // 4. メンバ変数
    QWidgetHandler* m_handler;
};
```

### Handlerクラス
```cpp
class QWidgetHandler : public QObject {
    Q_OBJECT
public:
    // 1. コンストラクタ/デストラクタ
    explicit QWidgetHandler(QWidget* widget = nullptr);
    ~QWidgetHandler();

    // 2. コールバック設定
    void setDestroyedCallback(void (*callback)(void*));
    void setWindowTitleChangedCallback(void (*callback)(void*, const char*));

public slots:
    // 3. シグナル受信スロット
    void onDestroyed();
    void onWindowTitleChanged(const QString& title);

private:
    // 4. メンバ変数
    QWidget* m_widget;
    void (*m_destroyedCallback)(void*);
    void (*m_windowTitleChangedCallback)(void*, const char*);
};
```

### C API
```cpp
// 1. オブジェクト管理
void* QWidget_create(void* parent);
void QWidget_delete(void* widget);

// 2. プロパティ操作
void QWidget_setWindowTitle(void* widget, const char* title);
const char* QWidget_windowTitle(void* widget);

// 3. アクション
void QWidget_show(void* widget);
void QWidget_hide(void* widget);

// 4. コールバック設定
void QWidget_setDestroyedCallback(void* widget, void (*callback)(void*));
```

## 6.4 コード構造のガイドライン

1. 一貫性
   - 同じパターンを一貫して使用
   - 命名規則を厳格に守る
   - レイアウトを統一する

2. 責任の分離
   - Bindクラス: Qt機能のラッピング
   - Handlerクラス: シグナル/スロット処理
   - C API: C言語インターフェース

3. エラー処理
   - 早期リターン
   - NULL チェック
   - 型チェック
   - エラー状態の伝播

4. メモリ管理
   - 所有権の明確化
   - リソースの適切な解放
   - 循環参照の防止
   - リークの防止
