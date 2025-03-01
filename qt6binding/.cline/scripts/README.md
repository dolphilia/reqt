# スクリプトツール

## generate_clinerules.py

`.clinerules`ファイルを生成するためのスクリプトです。

### セットアップ

1. 仮想環境のアクティベート:
```bash
# 初回のみ
source .cline/venv/bin/activate
pip install pyyaml

# 2回目以降
source .cline/venv/bin/activate
```

2. 実行権限の確認:
```bash
chmod +x .cline/scripts/generate_clinerules.py
```

### 使用方法

```bash
# 仮想環境がアクティブな状態で
cd /path/to/project
.cline/scripts/generate_clinerules.py
```

### 機能

1. `.cline/rules/`ディレクトリ内のMarkdownファイルを結合
2. `.cline/roomodes/`ディレクトリ内のカスタムモード定義を処理
3. メモリバンク構造の生成と管理
4. 継承関係の実装ガイドの生成
5. 以下のファイルを生成：
   - `.clinerules`: 結合されたルール定義
   - `.roomodes`: カスタムモード定義（JSON形式）
   - `memory_structure.md`: メモリバンク構造の定義

### ファイル構造

```
.cline/
├── venv/              # Python仮想環境
├── rules/             # ルール定義ファイル
│   ├── index.md
│   ├── coding_style/
│   │   ├── 1_file_structure.md
│   │   ├── 2_naming_conventions.md
│   │   └── ...
│   ├── error_handling/
│   ├── memory_management/
│   ├── signal_slot/
│   ├── inheritance/
│   ├── build_deploy/
│   └── version_release/
├── memory/            # メモリバンク構造
│   ├── projectbrief.md
│   ├── bindingContext.md
│   ├── bindingPatterns.md
│   ├── techContext.md
│   ├── activeContext.md
│   └── progress.md
├── roomodes/          # カスタムモード定義（オプション）
│   └── *.md
└── scripts/
    ├── README.md
    └── generate_clinerules.py
```

### フロントマター

Markdownファイルは以下のようなYAMLフロントマターを含むことができます：

```markdown
---
name: モード名
version: 1.0.0
groups:
  - グループ1
  - グループ2
---

コンテンツ...
```

### メモリバンク構造

メモリバンク構造は以下の要素で構成されます：

1. プロジェクト概要 (projectbrief.md)
   - プロジェクトの目的
   - 対象クラス
   - 品質要件
   - 完了の定義
   - 制約事項
   - リスクと対策

2. バインディングコンテキスト (bindingContext.md)
   - 基本原則
   - C言語インターフェース設計
   - メモリ管理
   - エラー処理
   - シグナル/スロット
   - スレッド安全性
   - パフォーマンス

3. バインディングパターン (bindingPatterns.md)
   - バインディングクラス
   - ハンドラクラス
   - C API
   - 継承
   - シグナル/スロット
   - エラー処理
   - メモリ管理
   - テスト

4. 技術コンテキスト (techContext.md)
   - 開発要件
   - Qt6要件
   - ビルド設定
   - コンパイル要件
   - 開発環境
   - テスト環境
   - デバッグ環境
   - パフォーマンス要件
   - 制約事項

5. アクティブコンテキスト (activeContext.md)
   - 実装状況
   - 最近の変更
   - 現在の課題
   - 次のステップ
   - 注意事項

6. 進捗状況 (progress.md)
   - 実装済み機能
   - 実装品質
   - テスト状況
   - ドキュメント状況
   - 残タスク
   - 次回リリース目標

### 注意事項

- `_`で始まるファイルは処理対象外
- ファイルは名前順に結合
- UTF-8エンコーディングを使用
- スクリプトは必ず仮想環境内で実行すること
- メモリバンク構造は定期的に更新すること
- 継承関係の実装は適切なガイドラインに従うこと
