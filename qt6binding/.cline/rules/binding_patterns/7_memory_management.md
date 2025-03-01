# メモリ管理パターン

## 7.1 リソース確保パターン
```cpp
// 1. 単一リソース
void* obj = [QtClass]_create(NULL);
if (!obj) return NULL;
// 使用
[QtClass]_delete(obj);

// 2. 複数リソース
void* obj1 = [QtClass1]_create(NULL);
if (!obj1) return NULL;

void* obj2 = [QtClass2]_create(obj1);
if (!obj2) {
    [QtClass1]_delete(obj1);
    return NULL;
}
```

## 7.2 文字列管理パターン
```cpp
// 文字列の取得
const char* str = [QtClass]_getText(ptr);
// 使用
// 注: 次のAPI呼び出しまで有効

// 文字列の設定
[QtClass]_setText(ptr, "text");
// 注: 内部でコピーを作成
```

## 7.3 実装のポイント
1. リソースの所有権
   - 明示的な所有権移転
   - 親子関係による自動管理
   - 一時リソースの管理

2. メモリ解放
   - 適切なタイミングでの解放
   - リソースリークの防止
   - 循環参照の回避

3. スレッド安全性
   - スレッドセーフな解放
   - 同期制御の実装
   - 競合状態の防止

4. エラー処理
   - メモリ確保失敗の処理
   - 部分的な解放
   - クリーンアップ処理
