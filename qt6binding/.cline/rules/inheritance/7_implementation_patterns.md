# 継承メソッドの実装パターン

## 7.1 基本原則
```markdown
1. 継承の扱い
   - Qt6クラスの多くはQObjectやQWidgetなどを継承している
   - C言語では継承を直接表現できない
   - 継承元のメソッドもバインディングに含める必要がある

2. コード効率化
   - すべてのメソッドを再実装せず、継承元の関数を活用
   - 既存のバインディング関数をラップして再利用
   - 重複コードを最小限に抑える
```

## 7.2 実装パターン
```c
// 1. 継承元の関数を直接利用
void QPushButton_setStyleSheet(void* button, const char* styleSheet) {
    // QWidgetの関数を再利用
    QWidget_setStyleSheet(button, styleSheet);
}

// 2. 型変換を含む実装
void QDialog_setLayout(void* dialog, void* layout) {
    // QWidgetのメソッドを利用
    QWidget_setLayout(dialog, layout);
}

// 3. 追加処理が必要な場合
void QMainWindow_setMenuBar(void* window, void* menuBar) {
    // 型チェックと追加処理
    if (!is_type(window, "QMainWindow")) return;
    QWidget_setParent(menuBar, window);  // 継承元の処理
    // QMainWindow固有の処理
    static_cast<QMainWindow*>(window)->setMenuBar(
        static_cast<QMenuBar*>(menuBar));
}
```

## 7.3 実装例
```cpp
// 1. スタイルシートの設定
// QWidget（基底クラス）の実装
void QWidget_setStyleSheet(void* widget, const char* styleSheet) {
    if (auto* w = safe_cast<QWidget>(widget)) {
        w->setStyleSheet(QString::fromUtf8(styleSheet));
    }
}

// QPushButton（派生クラス）の実装
void QPushButton_setStyleSheet(void* button, const char* styleSheet) {
    // 基底クラスの関数を再利用
    QWidget_setStyleSheet(button, styleSheet);
}

// 2. イベントハンドリング
// QWidget（基底クラス）の実装
void QWidget_show(void* widget) {
    if (auto* w = safe_cast<QWidget>(widget)) {
        w->show();
    }
}

// QDialog（派生クラス）の実装
void QDialog_show(void* dialog) {
    // 基底クラスの関数を再利用
    QWidget_show(dialog);
}
```

## 7.4 実装の選択基準
```markdown
1. 直接再利用
   - 継承元の実装で十分な場合
   - 追加の処理が不要な場合
   - 型変換のみが必要な場合

2. ラッパー実装
   - 追加の検証が必要な場合
   - エラー処理を追加する場合
   - パラメータの変換が必要な場合

3. 完全な再実装
   - 派生クラス固有の処理が必要な場合
   - 継承元の動作を変更する場合
   - パフォーマンスの最適化が必要な場合
```

## 7.5 実装のガイドライン
```markdown
1. 基本方針
   - 可能な限り継承元の関数を再利用
   - 重複コードを避ける
   - 保守性を重視

2. 実装手順
   - 継承元の機能を確認
   - 必要な追加処理を特定
   - 適切な実装パターンを選択

3. 注意点
   - 型の安全性を確保
   - エラー処理を適切に実装
   - パフォーマンスを考慮
```

## 7.6 ドキュメント例
```c
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
void QPushButton_setStyleSheet(void* button, const char* styleSheet) {
    QWidget_setStyleSheet(button, styleSheet);
}
