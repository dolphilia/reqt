# コメント

## 3.1 クラスコメント
```cpp
/**
 * @brief クラスの説明
 * @details 詳細な説明
 */
class SomeClass {
    /**
     * @brief メソッドの説明
     * @param param パラメータの説明
     * @return 戻り値の説明
     * @throws 例外の説明
     */
    ReturnType someMethod(ParamType param);
};
```

## 3.2 関数コメント
```cpp
/**
 * @brief スタイルシートを設定
 * 
 * この関数は QWidget::setStyleSheet() の機能を利用します。
 * QPushButtonはQWidgetを継承しているため、QWidget_setStyleSheet
 * を再利用することで実装を簡素化しています。
 *
 * @param button QPushButtonのポインタ
 * @param styleSheet 設定するスタイルシート
 * 
 * @note この実装はQWidgetの機能を直接利用するため、
 * QPushButton固有の追加処理は行いません。
 */
void QPushButton_setStyleSheet(void* button, const char* styleSheet);
```

## 3.3 コメントの種類

### ファイルヘッダーコメント
```cpp
/**
 * @file QWidgetBind.h
 * @brief QWidgetのバインディング実装
 * @author 作成者名
 * @date YYYY/MM/DD
 */
```

### インラインコメント
```cpp
void someFunction() {
    int count = 0;  // カウンタの初期化
    
    // 重要な処理の説明
    doSomething();
    
    /* 複数行の
       説明が必要な場合 */
    complexOperation();
}
```

### TODO コメント
```cpp
// TODO: パフォーマンスの最適化が必要
// FIXME: メモリリークの可能性あり
// NOTE: この実装は一時的なものです
```

## 3.4 コメントのガイドライン

1. コメントの目的
   - コードの意図を説明する
   - 複雑なロジックを解説する
   - APIの使用方法を示す
   - 注意点や制限事項を記述する

2. コメントの書き方
   - 簡潔で明確な文章を使用
   - 技術的な正確さを保つ
   - 最新の状態を維持する
   - 冗長な説明を避ける

3. コメントの更新
   - コード変更時に関連コメントも更新
   - 古いコメントは削除または修正
   - TODO コメントは定期的にレビュー
   - 誤解を招くコメントは避ける
