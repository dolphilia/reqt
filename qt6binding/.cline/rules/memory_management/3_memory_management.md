# メモリ管理方針

## 3.1 オブジェクトの寿命
```c
// 1. 明示的な作成と削除
void* obj = QWidget_create(NULL);
QWidget_delete(obj);

// 2. 親子関係による自動削除
void* parent = QWidget_create(NULL);
void* child = QWidget_create(parent);
QWidget_delete(parent);  // childは自動削除
```

## 3.2 リソース管理規則
1. create/deleteの対応を必須とする
2. 親オブジェクトの削除で子を自動削除
3. 一時リソースは関数内で解放
4. メモリリークの定期的な確認

## 3.3 文字列管理
```c
// 1. 文字列の取得
const char* text = QWidget_windowTitle(widget);
// 注: 次のAPI呼び出しまで有効

// 2. 文字列の設定
QWidget_setWindowTitle(widget, "Title");
// 注: 関数内でコピーを作成
