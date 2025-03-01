# ドキュメント管理

## 4.1 APIドキュメント
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

## 4.2 リリースノート
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

## 4.3 ドキュメント管理パターン

### 1. APIドキュメントの構成
```markdown
# クラス名

## 概要
クラスの基本的な説明と用途

## コンストラクタ
```c
void* ClassName_create(void* parent);
```
新しいインスタンスを作成します。

### パラメータ
- parent: 親オブジェクト（NULL可）

### 戻り値
- 成功時: 新しいインスタンスへのポインタ
- 失敗時: NULL

## メソッド
### method_name
```c
void ClassName_methodName(void* ptr, int param);
```
メソッドの説明

### パラメータ
- ptr: インスタンスへのポインタ
- param: パラメータの説明

### 戻り値
なし

## シグナル
### signalName
```c
void ClassName_setSignalCallback(void* ptr, void (*callback)(void*));
```
シグナルの説明

### パラメータ
- ptr: インスタンスへのポインタ
- callback: コールバック関数

## 使用例
```c
void* obj = ClassName_create(NULL);
ClassName_methodName(obj, 42);
ClassName_delete(obj);
```
```

### 2. リリースノートの構成
```markdown
# バージョン X.Y.Z (YYYY-MM-DD)

## 概要
このリリースの主な変更点や目的

## 新機能
- 機能1の説明
- 機能2の説明

## 変更点
- 変更1の説明
- 変更2の説明

## バグ修正
- バグ1の説明 (#123)
- バグ2の説明 (#124)

## 非推奨化
- 機能1 → 代替機能の説明
- 機能2 → 代替機能の説明

## 破壊的変更
- 変更1の説明と移行方法
- 変更2の説明と移行方法

## 既知の問題
- 問題1の説明 (#125)
- 問題2の説明 (#126)

## 謝辞
- 貢献者1
- 貢献者2
```

## 4.4 ドキュメント生成スクリプト

### 1. APIドキュメント生成
```python
#!/usr/bin/env python3
import os
import re
import sys

def generate_api_docs(source_dir, output_dir):
    """APIドキュメントを生成"""
    # ヘッダーファイルの収集
    headers = collect_headers(source_dir)
    
    # 各ヘッダーの解析
    for header in headers:
        doc = parse_header(header)
        write_doc(doc, output_dir)

def parse_header(header_file):
    """ヘッダーファイルを解析"""
    doc = {
        'class': '',
        'methods': [],
        'signals': [],
        'examples': []
    }
    
    with open(header_file, 'r') as f:
        content = f.read()
    
    # クラス名の抽出
    class_match = re.search(r'// Class: (\w+)', content)
    if class_match:
        doc['class'] = class_match.group(1)
    
    # メソッドの抽出
    method_matches = re.finditer(
        r'/\*\*\s*\n\s*\*(.*?)\*/\s*\n\s*(\w+\s+\w+\([^)]*\));',
        content,
        re.DOTALL
    )
    for match in method_matches:
        doc['methods'].append({
            'comment': match.group(1).strip(),
            'signature': match.group(2).strip()
        })
    
    return doc

def write_doc(doc, output_dir):
    """ドキュメントを書き出し"""
    output_file = os.path.join(
        output_dir,
        f"{doc['class']}.md"
    )
    
    with open(output_file, 'w') as f:
        f.write(f"# {doc['class']}\n\n")
        
        # メソッドの出力
        f.write("## Methods\n\n")
        for method in doc['methods']:
            f.write(f"### {method['signature']}\n")
            f.write(f"{method['comment']}\n\n")
```

### 2. リリースノート生成
```python
#!/usr/bin/env python3
import os
import sys
from datetime import datetime

def generate_release_notes(version, changes):
    """リリースノートを生成"""
    today = datetime.now().strftime('%Y-%m-%d')
    
    content = f"""# バージョン {version} ({today})

## 概要
{changes['summary']}

## 新機能
"""
    
    for feature in changes['features']:
        content += f"- {feature}\n"
    
    content += "\n## バグ修正\n"
    for fix in changes['fixes']:
        content += f"- {fix}\n"
    
    content += "\n## その他の改善\n"
    for improvement in changes['improvements']:
        content += f"- {improvement}\n"
    
    return content
```

## 4.5 ドキュメント管理のガイドライン

### 1. ドキュメントの構成
- 一貫した形式
- 明確な階層構造
- 適切な分類
- バージョン管理

### 2. 内容の品質
- 正確性の確保
- 完全性の確認
- 最新性の維持
- 例の充実

### 3. メンテナンス
- 定期的な更新
- 古い情報の削除
- リンクの確認
- フィードバックの反映

### 4. アクセシビリティ
- 検索性の向上
- ナビゲーションの改善
- 多言語対応
- フォーマットの統一
