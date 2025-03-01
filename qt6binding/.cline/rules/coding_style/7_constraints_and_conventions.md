# 制約と規約

## 7.1 禁止事項
- グローバル変数の使用
- using namespace の使用
- 複数の継承（特別な場合を除く）
- マジックナンバーの使用
- 暗黙の型変換
- 未初期化変数の使用
- goto文の使用
- 再帰的なマクロ
- インライン関数の過剰な使用
- 過度に複雑な条件式

## 7.2 推奨事項
- const の積極的な使用
- スマートポインタの使用
- 早期リターン
- 小さな関数
- 明示的な型変換
- 範囲ベースのforループ
- nullptr の使用（NULL の代わりに）
- override キーワードの使用
- noexcept の適切な使用
- コピー/ムーブの明示的な制御

## 7.3 バインディング固有の規約

### 型変換
```cpp
// 推奨
auto* widget = static_cast<QWidget*>(ptr);
auto* button = qobject_cast<QPushButton*>(widget);

// 非推奨
QWidget* widget = (QWidget*)ptr;
QPushButton* button = dynamic_cast<QPushButton*>(widget);
```

### メモリ管理
```cpp
// 推奨
void* widget = QWidget_create(parent);  // 親が所有権を持つ
QWidget_delete(widget);                 // 親がない場合は明示的に削除

// 非推奨
auto* widget = new QWidget();  // 生のnew/deleteを使用
delete widget;
```

### エラー処理
```cpp
// 推奨
if (!ptr) return NULL;
if (!is_valid(ptr)) return ERROR_INVALID;

// 非推奨
assert(ptr);  // 実行時アサーションに依存
if (ptr == NULL) throw std::exception();  // C++例外を使用
```

## 7.4 セキュリティ規約

### 入力検証
```cpp
// 推奨
void QWidget_setWindowTitle(void* widget, const char* title) {
    if (!widget || !title) return;
    if (strlen(title) > MAX_TITLE_LENGTH) return;
    // ...
}

// 非推奨
void QWidget_setWindowTitle(void* widget, const char* title) {
    static_cast<QWidget*>(widget)->setWindowTitle(title);
}
```

### リソース管理
```cpp
// 推奨
class ScopedResource {
    void* ptr;
public:
    explicit ScopedResource(void* p) : ptr(p) {}
    ~ScopedResource() { if (ptr) cleanup(ptr); }
};

// 非推奨
void* ptr = acquire_resource();
// リソースの使用
release_resource(ptr);  // 例外時にリークする可能性
```

## 7.5 パフォーマンス規約

### メモリ効率
```cpp
// 推奨
void process_data(const QString& data);  // 参照渡し
QString get_data() const&;               // const参照戻り値

// 非推奨
void process_data(QString data);         // 値渡し
QString get_data();                      // 値戻り
```

### 計算効率
```cpp
// 推奨
if (container.empty()) return;           // 早期リターン
for (const auto& item : container) {}    // 範囲for

// 非推奨
if (!container.empty()) {                // ネストが深くなる
    // 処理
}
for (int i = 0; i < container.size(); ++i) {}  // 従来のfor
