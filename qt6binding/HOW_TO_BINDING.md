# Qt クラスの C 言語バインディング作成手順

## 序論

Qt は強力な C++ フレームワークですが、C 言語からも使用できるようにバインディングを作成することができます。本ドキュメントでは、Qt クラスを C 言語から利用可能にするための体系的なアプローチを解説します。

## 基本アーキテクチャ

Qt クラスの C 言語バインディングは主に以下の 4 つのコンポーネントで構成されます：

1. **C API ヘッダファイル (`q<classname>.h`)**
   - C 言語から利用するための関数宣言
   - コールバック型定義
   - 列挙型や定数の定義

2. **C++ バインディングクラス (`<ClassName>Bind`)**
   - 元の Qt クラスを継承
   - C API 関数からアクセスされるインターフェース提供
   - 保護されたメソッドの公開

3. **ハンドラークラス (`<ClassName>Handler`)**
   - シグナルやイベントを C コールバックに変換
   - コールバックの管理と呼び出し

4. **C API 実装ファイル (`<ClassName>CAPI.cpp`)**
   - C API ヘッダで宣言された関数の実装
   - データ型の変換とメモリ管理

## 詳細な実装手順

### ステップ 1: クラス分析とマッピング設計

1. **クラスの選定と分析**：
   - バインディングを作成したい Qt クラス（例：`QObject`）を選び、API を詳細に調査
   - [Qt ドキュメント](https://doc.qt.io/)を参照し、クラスのすべての公開/保護メソッド、シグナル、スロットを整理

2. **C API マッピングの設計**：
   - 各メソッドの C 言語関数への変換方法を決定
   - シグナルをコールバック関数として公開する方法を設計
   - 保護メソッドへのアクセス方法を確立
   - 型変換の戦略を立てる（特に Qt 固有の型）

### ステップ 2: C API ヘッダファイルの作成

1. **基本構造**：
```c++
#ifndef C_Q_OBJECT_H
#define C_Q_OBJECT_H

#ifdef __cplusplus
extern "C" {
#endif

// 型定義と関数宣言

#ifdef __cplusplus
}
#endif

#endif // C_Q_OBJECT_H
```


2. **オブジェクトライフサイクル関数**：
```c++
// オブジェクト作成・削除
void* QObject_create(void* parent);
void QObject_delete(void* object);
```


3. **メソッドマッピング関数**：
   - 命名規則：`<ClassName>_<methodName>`
   - 第一引数は通常 `void* object`（対象オブジェクト）
   - オーバーロードメソッドは接尾辞（`_2`, `_3` など）で区別

```c++
bool QObject_blockSignals(void* object, bool block);
void QObject_setObjectName(void* object, const char* name);
const char* QObject_objectName(void* object);
```


4. **コールバック定義**：
```c++
// シグナルコールバック型定義
typedef void (*QObject_DestroyedCallback)(void* context, void* obj);
typedef void (*QObject_ObjectNameChangedCallback)(void* context, const char* name);

// コールバック設定関数
void QObject_setDestroyedCallback(void* object, QObject_DestroyedCallback callback);
void QObject_setObjectNameChangedCallback(void* object, QObject_ObjectNameChangedCallback callback);
```


5. **イベント処理コールバック**：
```c++
typedef bool (*QObject_EventCallback)(void* context, void* event);
void QObject_setEventCallback(void* object, QObject_EventCallback callback);
```


6. **列挙型と定数**：
```c++
// Qt::ConnectionType の定数
#define QOBJECT_AUTO_CONNECTION 0
#define QOBJECT_DIRECT_CONNECTION 1
#define QOBJECT_QUEUED_CONNECTION 2
```


### ステップ 3: ハンドラークラスの実装

1. **クラス定義** (`QObjectHandler.h`):
```c++
class QObjectHandler : public QObject {
    Q_OBJECT
private:
    // コールバックポインタ
    QObject_DestroyedCallback destroyedCallback;
    QObject_ObjectNameChangedCallback objectNameChangedCallback;
    QObject_EventCallback eventCallback;
    // コンテキスト（通常 this ポインタ）
    void* context;

public:
    explicit QObjectHandler(QObject* parent = nullptr);
    
    // コールバック設定メソッド
    void setDestroyedCallback(QObject_DestroyedCallback callback);
    void setObjectNameChangedCallback(QObject_ObjectNameChangedCallback callback);
    void setEventCallback(QObject_EventCallback callback);
    
    // コールバック存在チェック
    bool hasEventCallback() const { return eventCallback != nullptr; }

public slots:
    // シグナル受信スロット
    void onDestroyed(QObject* obj = nullptr) const;
    void onObjectNameChanged(const QString& name) const;
    
    // イベント処理メソッド
    void onEvent(QEvent* event) const;
};
```


2. **メソッド実装** (`QObjectHandler.cpp`):
```c++
QObjectHandler::QObjectHandler(QObject* parent)
    : QObject(parent)
    , destroyedCallback(nullptr)
    , objectNameChangedCallback(nullptr)
    , eventCallback(nullptr)
    , context(this) {
}

void QObjectHandler::setDestroyedCallback(QObject_DestroyedCallback callback) {
    destroyedCallback = callback;
}

void QObjectHandler::onDestroyed(QObject* obj) const {
    if (destroyedCallback) {
        destroyedCallback(context, obj);
    }
}

// 他のメソッドも同様に実装
```


### ステップ 4: バインディングクラスの実装

1. **クラス定義** (`QObjectBind.h`):
```c++
class QObjectBind : public QObject {
    Q_OBJECT
private:
    QObjectHandler* handler;

public:
    explicit QObjectBind(QObject* parent = nullptr);
    ~QObjectBind() override;
    
    // コールバック設定メソッド
    void setDestroyedCallback(QObject_DestroyedCallback callback) const;
    void setObjectNameChangedCallback(QObject_ObjectNameChangedCallback callback) const;
    void setEventCallback(QObject_EventCallback callback) const;
    
    // 保護メソッドの公開
    bool isSignalConnected(const QMetaMethod& signal) const;
    int receivers(const char* signal) const;
    QObject* sender() const;

protected:
    // 仮想メソッドのオーバーライド
    bool event(QEvent* e) override;
    void childEvent(QChildEvent* event) override;
    void timerEvent(QTimerEvent* event) override;
};
```


2. **メソッド実装** (`QObjectBind.cpp`):
```c++
QObjectBind::QObjectBind(QObject* parent)
    : QObject(parent)
    , handler(new QObjectHandler(this)) {
    // シグナル接続
    connect(this, &QObject::destroyed, handler, &QObjectHandler::onDestroyed);
    connect(this, &QObject::objectNameChanged, handler, &QObjectHandler::onObjectNameChanged);
}

QObjectBind::~QObjectBind() {
    delete handler;
}

void QObjectBind::setDestroyedCallback(QObject_DestroyedCallback callback) const {
    handler->setDestroyedCallback(callback);
}

bool QObjectBind::event(QEvent* e) {
    if (handler && handler->hasEventCallback()) {
        handler->onEvent(e);
    }
    return QObject::event(e);
}

// 他のメソッドも同様に実装
```


### ステップ 5: C API 実装

1. **基本構造** (`QObjectCAPI.cpp`):
```c++
#include "QObjectBind.h"
#include <QtCore/QString>
#include <QtCore/QMetaObject>

extern "C" {

// 関数実装

} // extern "C"
```


2. **オブジェクト生成/削除**:
```c++
void* QObject_create(void* parent) {
    return new QObjectBind(static_cast<QObject*>(parent));
}

void QObject_delete(void* object) {
    delete static_cast<QObjectBind*>(object);
}
```


3. **メソッド実装**:
```c++
bool QObject_blockSignals(void* object, bool block) {
    return static_cast<QObjectBind*>(object)->blockSignals(block);
}

void QObject_setObjectName(void* object, const char* name) {
    static_cast<QObjectBind*>(object)->setObjectName(QString::fromUtf8(name));
}

const char* QObject_objectName(void* object) {
    // 注意: 返される文字列の寿命に注意
    // 実際の実装では複製やメモリ管理が必要
    return static_cast<QObjectBind*>(object)->objectName().toUtf8().constData();
}
```


4. **コレクション処理**:
```c++
void** QObject_children(void* object, int* count) {
    QList<QObject*> children = static_cast<QObjectBind*>(object)->children();
    *count = children.size();
    void** result = new void*[children.size()];
    for (int i = 0; i < children.size(); i++) {
        result[i] = children[i];
    }
    return result;
}
```


5. **コールバック設定**:
```c++
void QObject_setDestroyedCallback(void* object, QObject_DestroyedCallback callback) {
    static_cast<QObjectBind*>(object)->setDestroyedCallback(callback);
}
```


### ステップ 6: メモリ管理と型変換の実装

1. **文字列変換**:
   - **C → Qt**: `QString::fromUtf8(c_string)`
   - **Qt → C**: 一時的なバッファか新しいメモリ割り当て
```c++
char* copyString(const QString& str) {
       QByteArray utf8 = str.toUtf8();
       char* result = new char[utf8.size() + 1];
       strcpy(result, utf8.constData());
       return result;
   }
```


2. **コレクション変換**:
   - **QList → C 配列**:
```c++
void** convertList(const QList<QObject*>& list, int* size) {
       *size = list.size();
       void** array = new void*[list.size()];
       for (int i = 0; i < list.size(); i++) {
           array[i] = list[i];
       }
       return array;
   }
```


3. **メモリ解放ユーティリティ**:
```c++
void QObject_freeString(char* str) {
    delete[] str;
}

void QObject_freeArray(void** array) {
    delete[] array;
}
```


### ステップ 7: ビルドシステムの設定

1. **CMake の設定例**:
```cmake
# CMakeLists.txt
cmake_minimum_required(VERSION 3.16)
project(qt6binding)

find_package(Qt6 REQUIRED COMPONENTS Core)

# Qt の MOC 処理を設定
set(CMAKE_AUTOMOC ON)

# ソースファイル
set(SOURCES
    src/QtCore/QObject/QObjectBind.cpp
    src/QtCore/QObject/QObjectHandler.cpp
    src/QtCore/QObject/QObjectCAPI.cpp
)

# ヘッダファイル
set(HEADERS
    src/QtCore/QObject/QObjectBind.h
    src/QtCore/QObject/QObjectHandler.h
    include/qobject.h
)

# ライブラリ作成
add_library(qt6binding ${SOURCES} ${HEADERS})
target_include_directories(qt6binding PUBLIC include src)
target_link_libraries(qt6binding PRIVATE Qt6::Core)
```


### ステップ 8: テストとバリデーション

1. **C 言語からのテスト**:
```c++
#include <stdio.h>
#include "qobject.h"

void objectNameChangedCallback(void* context, const char* name) {
    printf("Object name changed to: %s\n", name);
}

int main() {
    void* obj = QObject_create(NULL);
    
    QObject_setObjectNameChangedCallback(obj, objectNameChangedCallback);
    QObject_setObjectName(obj, "MyObject");
    
    const char* name = QObject_objectName(obj);
    printf("Current object name: %s\n", name);
    
    QObject_delete(obj);
    return 0;
}
```


## 実装上の重要な考慮点

### 1. メモリ管理と所有権

- **オブジェクト所有権**: C++ と C の間での明確な所有権移譲ルールを定義（誰がオブジェクトを解放するか）
- **一時オブジェクト**: API から返される文字列など一時オブジェクトのメモリ解放責任を明確に
- **リーク防止**: 適切なクリーンアップ関数を提供（特に文字列や配列）

### 2. 型変換の安全性

- **ポインタキャスト**: `static_cast` や明示的なキャストを適切に使用
- **数値型変換**: 整数型や浮動小数点型のサイズや符号に注意
- **文字列エンコード**: UTF-8 変換の一貫性を確保

### 3. エラー処理

- **例外処理**: C++ の例外を C のエラーコードに適切に変換
- **NULL チェック**: すべての入力ポインタの NULL チェック
- **エラー報告**: 明確なエラーコードとメッセージ

### 4. スレッド安全性

- **シグナル/スロット**: 異なるスレッドからのコールバック呼び出しに対応
- **共有リソース**: スレッド間で共有されるオブジェクトの同期
- **イベントループ**: イベントループの管理とスレッド間通信

### 5. パフォーマンス最適化

- **メモリ割り当て**: 頻繁な割り当て/解放を避ける
- **データコピー**: 不必要なデータコピーを最小限に
- **関数呼び出しオーバーヘッド**: 高頻度で呼び出される関数の最適化

## ドキュメントと例

各クラスのバインディングには次のドキュメントを添付するとよいでしょう：

1. **API リファレンス**: 各 C 関数の詳細な説明と使用例
2. **メモリ管理ガイド**: オブジェクトの作成、使用、破棄のルール
3. **型変換例**: 複雑なデータ型の変換方法
4. **包括的なサンプル**: 各機能を示す完全な例

## 結論

Qt クラスの C バインディング作成は複雑なプロセスですが、適切に設計・実装することで、C アプリケーションから Qt の強力な機能を活用できるようになります。本ドキュメントで説明したアーキテクチャとパターンに従うことで、保守性が高く、効率的で安全なバインディングを実現できます。