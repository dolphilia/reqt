# Qt6バインディングにおけるシグナル・スロットの継承実装

このドキュメントでは、Qt6バインディングでシグナル・スロットメカニズムを継承関係の中で適切に実装するための方法を説明します。

## 目次

1. [シグナル・スロットの基本概念](#シグナルスロットの基本概念)
2. [継承関係におけるシグナル・スロット](#継承関係におけるシグナルスロット)
3. [実装手順](#実装手順)
4. [具体的な実装例](#具体的な実装例)
5. [トラブルシューティング](#トラブルシューティング)

## シグナル・スロットの基本概念

Qtのシグナル・スロットは、オブジェクト間の通信メカニズムです。C言語バインディングでは、シグナルをコールバック関数として実装します。

基本的な実装パターン：

1. シグナルに対応するコールバック関数の型を定義
2. コールバック関数を設定するメソッドを実装
3. シグナル発生時にコールバック関数を呼び出す

## 継承関係におけるシグナル・スロット

継承関係では、基底クラスのシグナルは派生クラスでも利用できます。C言語バインディングでも同様に、基底クラスのシグナルに対応するコールバック関数を派生クラスでも設定・利用できるようにする必要があります。

例えば：
- `QObject`の`destroyed()`シグナルは`QWidget`でも利用可能
- `QWidget`の`customContextMenuRequested()`シグナルは`QPushButton`でも利用可能

## 実装手順

### 1. コールバック関数の型定義

各クラスのシグナルに対応するコールバック関数の型を定義します。

```cpp
// QObjectのシグナル用コールバック
typedef void (*ObjectDestroyedCallback)(void*);
typedef void (*ObjectNameChangedCallback)(void*, const QString*);

// QWidgetのシグナル用コールバック
typedef void (*WidgetCustomContextMenuRequestedCallback)(void*, const QPoint*);
```

### 2. Bindクラスでのコールバック設定メソッド

基底クラスと派生クラスの両方でコールバック設定メソッドを実装します。

```cpp
// QObjectBind.h
class QObjectBind {
public:
    // ...
    static void setDestroyedCallback(void* object, ObjectDestroyedCallback callback);
    static void setObjectNameChangedCallback(void* object, ObjectNameChangedCallback callback);
};

// QWidgetBind.h
class QWidgetBind {
public:
    // ...
    // QWidgetのシグナル
    static void setCustomContextMenuRequestedCallback(void* widget, WidgetCustomContextMenuRequestedCallback callback);
    
    // QObjectのシグナルを委譲
    static void setDestroyedCallback(void* widget, ObjectDestroyedCallback callback) {
        QObjectBind::setDestroyedCallback(widget, callback);
    }
    
    static void setObjectNameChangedCallback(void* widget, ObjectNameChangedCallback callback) {
        QObjectBind::setObjectNameChangedCallback(widget, callback);
    }
};
```

### 3. CAPI関数の実装

基底クラスと派生クラスの両方でCAPI関数を実装します。

```cpp
// QObjectCAPI.cpp
extern "C" {
    void QObject_setDestroyedCallback(void* object, void (*callback)(void*)) {
        QObjectBind::setDestroyedCallback(object, callback);
    }
    
    void QObject_setObjectNameChangedCallback(void* object, void (*callback)(void*, const char*)) {
        // 型変換が必要な場合は適切に処理
        QObjectBind::setObjectNameChangedCallback(object, 
            reinterpret_cast<ObjectNameChangedCallback>(callback));
    }
}

// QWidgetCAPI.cpp
extern "C" {
    // QWidgetのシグナル
    void QWidget_setCustomContextMenuRequestedCallback(void* widget, void (*callback)(void*, const void*)) {
        QWidgetBind::setCustomContextMenuRequestedCallback(widget,
            reinterpret_cast<WidgetCustomContextMenuRequestedCallback>(callback));
    }
    
    // QObjectのシグナルを委譲
    void QWidget_setDestroyedCallback(void* widget, void (*callback)(void*)) {
        QWidgetBind::setDestroyedCallback(widget, callback);
    }
    
    void QWidget_setObjectNameChangedCallback(void* widget, void (*callback)(void*, const char*)) {
        QWidgetBind::setObjectNameChangedCallback(widget,
            reinterpret_cast<ObjectNameChangedCallback>(callback));
    }
}
```

## 具体的な実装例

以下に、QObjectのdestroyedシグナルをQWidgetで利用する具体的な実装例を示します。

### Handler層

```cpp
// BindQObject.h
class BindQObject : public QObject {
    Q_OBJECT
public:
    // ...
    void setDestroyedCallback(ObjectDestroyedCallback callback);
    
private slots:
    void onDestroyed();
    
private:
    ObjectDestroyedCallback destroyedCallback;
};

// BindQWidget.h
class BindQWidget : public QWidget {
    Q_OBJECT
public:
    // ...
    // QWidgetのシグナル用
    void setCustomContextMenuRequestedCallback(WidgetCustomContextMenuRequestedCallback callback);
    
    // QObjectのシグナルは基底クラスから継承されるので、
    // 明示的に再実装する必要はない
    
private slots:
    void onCustomContextMenuRequested(const QPoint &pos);
    
private:
    WidgetCustomContextMenuRequestedCallback customContextMenuRequestedCallback;
};
```

### Bind層

```cpp
// QObjectBind.cpp
void QObjectBind::setDestroyedCallback(void* object, ObjectDestroyedCallback callback)
{
    if (object) {
        static_cast<BindQObject*>(object)->setDestroyedCallback(callback);
    }
}

// QWidgetBind.cpp
void QWidgetBind::setCustomContextMenuRequestedCallback(void* widget, WidgetCustomContextMenuRequestedCallback callback)
{
    if (widget) {
        static_cast<BindQWidget*>(widget)->setCustomContextMenuRequestedCallback(callback);
    }
}

// QObjectのシグナルを委譲するメソッドはヘッダーでインライン実装
```

### CAPI層

```cpp
// QObjectCAPI.cpp
extern "C" {
    void QObject_setDestroyedCallback(void* object, void (*callback)(void*))
    {
        QObjectBind::setDestroyedCallback(object, callback);
    }
}

// QWidgetCAPI.cpp
extern "C" {
    void QWidget_setCustomContextMenuRequestedCallback(void* widget, void (*callback)(void*, const void*))
    {
        QWidgetBind::setCustomContextMenuRequestedCallback(widget,
            reinterpret_cast<WidgetCustomContextMenuRequestedCallback>(callback));
    }
    
    void QWidget_setDestroyedCallback(void* widget, void (*callback)(void*))
    {
        QWidgetBind::setDestroyedCallback(widget, callback);
    }
}
```

### C言語側での使用例

```c
// QObjectのdestroyedシグナルを利用
void on_object_destroyed(void* object)
{
    printf("Object destroyed: %p\n", object);
}

void setup_object()
{
    void* obj = QObject_create(NULL);
    QObject_setDestroyedCallback(obj, on_object_destroyed);
}

// QWidgetでQObjectのdestroyedシグナルを利用
void setup_widget()
{
    void* widget = QWidget_create(NULL);
    QWidget_setDestroyedCallback(widget, on_object_destroyed);
}
```

## 複雑なシグナルの処理

パラメータが複雑なシグナルの場合、コールバックコンテキストを使用して処理します。

```cpp
// コールバックコンテキスト
namespace {
    struct CallbackContext {
        static void (*current_callback)(void*, const char*);
        
        static void wrapper(void* obj, const QString* name) {
            if (current_callback) {
                current_callback(obj, name->toUtf8().constData());
            }
        }
    };
    
    // 静的メンバ変数の定義
    void (*CallbackContext::current_callback)(void*, const char*) = nullptr;
}

// コールバック設定
void QObject_setObjectNameChangedCallback(void* object, void (*callback)(void*, const char*))
{
    auto obj = static_cast<BindQObject*>(object);
    CallbackContext::current_callback = callback;
    obj->setObjectNameChangedCallback(CallbackContext::wrapper);
}
```

## トラブルシューティング

### シグナルが発火しない問題

**問題**: シグナルが発火してもコールバックが呼ばれない

**解決策**:
1. シグナルとスロットの接続が正しく行われているか確認する
2. コールバック関数が正しく設定されているか確認する
3. コールバック関数がnullでないかチェックを追加する

### パラメータ変換の問題

**問題**: シグナルのパラメータがコールバック関数に正しく渡されない

**解決策**:
1. 型変換が正しく行われているか確認する
2. 文字列などのリソースの寿命を適切に管理する
3. 必要に応じてラッパー関数を使用する

### メモリリークの問題

**問題**: シグナル処理でメモリリークが発生する

**解決策**:
1. 一時オブジェクトの解放を確実に行う
2. コールバック内で確保したリソースを適切に解放する
3. オブジェクトの寿命とコールバックの関係を明確にする
