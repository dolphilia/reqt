# バージョン管理とリリースガイドライン

## 1. バージョニング規則

### 1.1 セマンティックバージョニング
```text
MAJOR.MINOR.PATCH (例: 1.2.3)

1. MAJOR: 互換性のない変更
   - APIの破壊的変更
   - 既存機能の削除
   - 動作の大幅な変更

2. MINOR: 後方互換性のある機能追加
   - 新しいクラスのバインディング追加
   - 既存クラスへのメソッド追加
   - オプショナルな機能の追加

3. PATCH: バグ修正
   - メモリリークの修正
   - クラッシュの修正
   - ドキュメントの修正
```

### 1.2 バージョン管理ファイル
```cmake
# version.cmake
set(QT6BINDING_VERSION_MAJOR 1)
set(QT6BINDING_VERSION_MINOR 0)
set(QT6BINDING_VERSION_PATCH 0)

set(QT6BINDING_VERSION
    "${QT6BINDING_VERSION_MAJOR}.${QT6BINDING_VERSION_MINOR}.${QT6BINDING_VERSION_PATCH}")

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/include/version.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/include/version.h
)
```

## 2. Git運用ルール

### 2.1 ブランチ戦略
```text
1. メインブランチ
   - main: 安定版のコード
   - develop: 開発版のコード

2. 機能ブランチ
   - feature/[機能名]: 新機能の開発
   例: feature/qwidget-binding

3. リリースブランチ
   - release/v[バージョン]: リリース準備
   例: release/v1.2.0

4. 修正ブランチ
   - hotfix/[問題]: 緊急バグ修正
   例: hotfix/memory-leak
```

### 2.2 コミットメッセージ
```text
# 基本形式
<type>: <description>

<details>

<notes>

# タイプ一覧
feat: 新機能
fix: バグ修正
update: 機能改善
refactor: リファクタリング
test: テスト関連
docs: ドキュメント
build: ビルド関連
ci: CI関連

# 例
feat: QWidgetバインディングの実装

- 基本的なメソッドの実装
- シグナル/スロットの処理
- メモリ管理の実装

Resolves #123
```

## 3. リリースプロセス

### 3.1 リリース準備
```bash
# 1. リリースブランチの作成
git checkout -b release/v1.2.0 develop

# 2. バージョン番号の更新
# version.cmakeの編集

# 3. CHANGELOGの更新
cat << EOF > CHANGELOG.md
# 1.2.0 (2025-03-01)

## 追加機能
- QWidgetバインディング
- QButtonバインディング
- QPushButtonバインディング

## バグ修正
- メモリリークの修正
- シグナル接続の問題修正

## その他の改善
- ドキュメントの更新
- テストカバレッジの向上
EOF

# 4. コミット
git add version.cmake CHANGELOG.md
git commit -m "release: バージョン1.2.0"
```

### 3.2 リリースチェックリスト
```markdown
## 前提条件の確認
- [ ] すべてのテストが成功
- [ ] メモリリークなし
- [ ] APIドキュメント更新済み
- [ ] CHANGELOGの更新

## ビルド確認
- [ ] Windows
  - [ ] Debug/Release
  - [ ] 32/64ビット
  - [ ] 依存関係の確認
- [ ] macOS
  - [ ] Intel/ARM
  - [ ] 依存関係の確認
- [ ] Linux
  - [ ] 主要ディストリビューション
  - [ ] 依存関係の確認

## パッケージング
- [ ] ヘッダファイルの包含
- [ ] ライブラリファイルの包含
- [ ] ドキュメントの包含
- [ ] ライセンスファイルの包含
- [ ] サンプルコードの包含
```

### 3.3 リリース手順
```bash
# 1. mainブランチへのマージ
git checkout main
git merge --no-ff release/v1.2.0
git tag -a v1.2.0 -m "バージョン1.2.0"

# 2. developブランチへのマージ
git checkout develop
git merge --no-ff release/v1.2.0

# 3. リリースブランチの削除
git branch -d release/v1.2.0

# 4. タグのプッシュ
git push origin main develop --tags
```

## 4. ドキュメント管理

### 4.1 APIドキュメント
```markdown
# バージョン別APIドキュメント
docs/
  ├── v1.0/
  │   ├── api/
  │   ├── examples/
  │   └── migration/
  └── v1.1/
      ├── api/
      ├── examples/
      └── migration/
```

### 4.2 リリースノート
```markdown
# バージョン1.2.0

## 主な変更点
- QWidgetバインディングの追加
- パフォーマンスの改善
- バグ修正

## 破壊的変更
なし

## 非推奨機能
- `old_function()` → `new_function()`に置き換え

## バグ修正
- #123: メモリリークの修正
- #124: シグナル接続の問題修正

## 既知の問題
- #125: 特定条件下でのクラッシュ
```

## 5. 品質管理

### 5.1 コードレビュー基準
```markdown
## レビュー項目
1. コーディング規約
   - 命名規則の遵守
   - フォーマットの一貫性
   - コメントの適切性

2. 機能
   - 仕様との一致
   - エッジケースの考慮
   - エラー処理の適切性

3. パフォーマンス
   - メモリ使用量
   - CPU使用量
   - 応答性能

4. テスト
   - ユニットテストの網羅性
   - エッジケースのテスト
   - パフォーマンステスト
```

### 5.2 リリース判定基準
```markdown
## 必須条件
1. テストカバレッジ
   - ライン: 80%以上
   - ブランチ: 70%以上
   - 関数: 90%以上

2. 静的解析
   - 重大な警告なし
   - 中程度の警告対応済み

3. パフォーマンス
   - ベースラインから20%以内
   - メモリリークなし

4. ドキュメント
   - API完全網羅
   - サンプルコード更新
   - 移行ガイド作成
```

## 6. 保守とサポート

### 6.1 バージョンサポート方針
```markdown
## サポート期間
1. LTSバージョン
   - 3年間のバグ修正
   - 2年間のセキュリティ修正

2. 通常バージョン
   - 1年間のバグ修正
   - 6ヶ月間のセキュリティ修正

## サポート終了プロセス
1. 告知
   - 6ヶ月前: 事前告知
   - 3ヶ月前: リマインダー
   - 1ヶ月前: 最終告知

2. 移行支援
   - 移行ガイドの提供
   - 移行ツールの提供
   - サポートの強化
```

### 6.2 バグ修正方針
```markdown
## 優先度
1. Critical
   - セキュリティ問題
   - クラッシュ
   - データ損失

2. High
   - 主要機能の不具合
   - パフォーマンス問題
   - 互換性問題

3. Medium
   - UI/UXの問題
   - 軽微な機能不具合
   - ドキュメントの誤り

4. Low
   - 体裁の問題
   - 機能改善要望
   - 最適化要望
