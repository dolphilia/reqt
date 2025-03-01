# リリースプロセス

## 3.1 リリース準備
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

## 3.2 リリースチェックリスト
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

## 3.3 リリース手順
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

## 3.4 リリーススクリプト

### 1. リリース準備スクリプト
```python
#!/usr/bin/env python3
import os
import sys
import subprocess
from datetime import datetime

def prepare_release(version):
    """リリースの準備を行う"""
    # リリースブランチの作成
    subprocess.run([
        'git', 'checkout', '-b',
        f'release/v{version}', 'develop'
    ])
    
    # バージョン番号の更新
    update_version_file(version)
    
    # CHANGELOGの更新
    update_changelog(version)
    
    # コミット
    subprocess.run([
        'git', 'add', 'version.cmake', 'CHANGELOG.md'
    ])
    subprocess.run([
        'git', 'commit', '-m',
        f'release: バージョン{version}'
    ])

def update_version_file(version):
    """バージョンファイルを更新"""
    major, minor, patch = version.split('.')
    content = f'''
set(QT6BINDING_VERSION_MAJOR {major})
set(QT6BINDING_VERSION_MINOR {minor})
set(QT6BINDING_VERSION_PATCH {patch})
'''
    with open('version.cmake', 'w') as f:
        f.write(content)

def update_changelog(version):
    """CHANGELOGを更新"""
    today = datetime.now().strftime('%Y-%m-%d')
    content = f'''# {version} ({today})

## 追加機能
- 新機能の説明

## バグ修正
- バグ修正の説明

## その他の改善
- 改善点の説明
'''
    with open('CHANGELOG.md', 'w') as f:
        f.write(content)
```

### 2. リリース実行スクリプト
```python
#!/usr/bin/env python3
import os
import sys
import subprocess

def execute_release(version):
    """リリースを実行"""
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
    
    # タグのプッシュ
    subprocess.run([
        'git', 'push', 'origin',
        'main', 'develop', '--tags'
    ])
```

## 3.5 リリースのガイドライン

### 1. リリース準備
- バージョン番号の選択
- 変更履歴の整理
- ドキュメントの更新
- テストの実施

### 2. 品質確認
- テストカバレッジの確認
- パフォーマンステスト
- メモリリークチェック
- 依存関係の確認

### 3. パッケージング
- 必要なファイルの確認
- ライセンスの確認
- ドキュメントの確認
- サンプルコードの確認

### 4. 配布
- リリースノートの作成
- パッケージの署名
- 配布チャネルの準備
- アナウンスの準備
