# Git運用ルール

## 2.1 ブランチ戦略
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

## 2.2 コミットメッセージ
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

## 2.3 ブランチ管理パターン

### 1. 機能開発フロー
```bash
# 1. 機能ブランチの作成
git checkout -b feature/new-widget develop

# 2. 開発作業
git add .
git commit -m "feat: 新しいウィジェットの実装"

# 3. developブランチへのマージ
git checkout develop
git merge --no-ff feature/new-widget

# 4. 機能ブランチの削除
git branch -d feature/new-widget
```

### 2. リリースフロー
```bash
# 1. リリースブランチの作成
git checkout -b release/v1.2.0 develop

# 2. バージョン番号の更新
# version.cmakeの編集

# 3. リリース準備のコミット
git commit -m "release: バージョン1.2.0の準備"

# 4. mainブランチへのマージ
git checkout main
git merge --no-ff release/v1.2.0
git tag -a v1.2.0 -m "バージョン1.2.0"

# 5. developブランチへのマージ
git checkout develop
git merge --no-ff release/v1.2.0

# 6. リリースブランチの削除
git branch -d release/v1.2.0
```

## 2.4 Git運用スクリプト

### 1. ブランチ管理スクリプト
```python
#!/usr/bin/env python3
import subprocess
import sys

def create_feature_branch(feature_name):
    """機能ブランチを作成"""
    subprocess.run([
        'git', 'checkout', '-b',
        f'feature/{feature_name}', 'develop'
    ])

def finish_feature_branch(feature_name):
    """機能ブランチを完了"""
    subprocess.run([
        'git', 'checkout', 'develop'
    ])
    subprocess.run([
        'git', 'merge', '--no-ff',
        f'feature/{feature_name}'
    ])
    subprocess.run([
        'git', 'branch', '-d',
        f'feature/{feature_name}'
    ])
```

### 2. リリース管理スクリプト
```python
#!/usr/bin/env python3
import subprocess
import sys

def create_release_branch(version):
    """リリースブランチを作成"""
    subprocess.run([
        'git', 'checkout', '-b',
        f'release/v{version}', 'develop'
    ])

def finish_release_branch(version):
    """リリースブランチを完了"""
    # mainブランチへのマージ
    subprocess.run(['git', 'checkout', 'main'])
    subprocess.run([
        'git', 'merge', '--no-ff',
        f'release/v{version}'
    ])
    subprocess.run([
        'git', 'tag', '-a',
        f'v{version}',
        '-m', f'バージョン{version}'
    ])
    
    # developブランチへのマージ
    subprocess.run(['git', 'checkout', 'develop'])
    subprocess.run([
        'git', 'merge', '--no-ff',
        f'release/v{version}'
    ])
    
    # リリースブランチの削除
    subprocess.run([
        'git', 'branch', '-d',
        f'release/v{version}'
    ])
```

## 2.5 Git運用のガイドライン

### 1. ブランチ運用
- ブランチの命名規則
- マージの方針
- コンフリクトの解決
- クリーンアップの基準

### 2. コミット管理
- コミットの粒度
- メッセージの書き方
- 変更の分類
- レビューの基準

### 3. タグ管理
- タグの付け方
- バージョン番号との対応
- 説明の書き方
- 署名の方針

### 4. コラボレーション
- プルリクエストの運用
- レビュープロセス
- マージの承認フロー
- コントリビューションの管理
