#!/usr/bin/env python3
"""
プロンプトファイルを結合して .clinerules を生成するスクリプト
"""

import os
import sys
import json
import yaml
import re
from typing import Dict, List, Tuple, TypedDict, Optional

class RooMode(TypedDict):
    slug: str
    name: str
    roleDefinition: str
    groups: List[str]
    source: str
    __filename: str

def get_script_dir() -> str:
    """スクリプトのディレクトリパスを取得"""
    return os.path.dirname(os.path.abspath(__file__))

def parse_front_matter(content: str) -> Tuple[Dict, str]:
    """
    Markdownファイルからフロントマターを解析
    """
    if content.startswith('---\n'):
        parts = content.split('---\n', 2)
        if len(parts) >= 3:
            try:
                front_matter = yaml.safe_load(parts[1])
                return front_matter or {}, parts[2]
            except yaml.YAMLError:
                pass
    return {}, content

def should_include_file(file_path: str) -> bool:
    """
    ファイルを含めるべきかどうかを判断
    """
    # 除外するファイルやディレクトリ
    exclude_patterns = [
        'README.md',
        'scripts/',
        'venv/',
        'project_structure.md',
        'usage_guide.md',
        'development_guide.md',
        'clinerules.md',
        'memory/',  # memory/ディレクトリを除外
        'roomodes/'  # roomodes/ディレクトリを除外
    ]
    
    # 除外パターンに一致する場合はFalse
    rel_path = os.path.relpath(file_path, os.path.dirname(os.path.dirname(get_script_dir())))
    for pattern in exclude_patterns:
        if pattern in rel_path:
            return False
    
    # .mdファイルで、_で始まらないものを含める
    return file_path.endswith('.md') and not os.path.basename(file_path).startswith('_')

def get_category_order() -> Dict[str, int]:
    """
    カテゴリの順序を定義
    """
    return {
        'coding_style': 1,
        'error_handling': 2,
        'memory_management': 3,
        'signal_slot': 4,
        'inheritance': 5,
        'thread_safety': 6,
        'performance': 7,
        'build_deploy': 8,
        'version_release': 9
    }

def get_file_order(file_path: str) -> Tuple[int, int]:
    """
    ファイルの順序を取得
    カテゴリの順序と、ファイル名の番号から順序を決定
    """
    category_order = get_category_order()
    
    # カテゴリを取得
    parts = file_path.split(os.sep)
    category = next((p for p in parts if p in category_order), '')
    cat_order = category_order.get(category, 999)
    
    # ファイル名から番号を取得
    filename = os.path.basename(file_path)
    match = re.match(r'(\d+)_', filename)
    file_order = int(match.group(1)) if match else 999
    
    return (cat_order, file_order)

def collect_markdown_files(directory: str) -> List[str]:
    """
    指定されたディレクトリから対象となるMarkdownファイルを収集し、
    カテゴリとファイル番号に基づいて順序付け
    """
    markdown_files = []
    for root, _, files in os.walk(directory):
        for file in files:
            file_path = os.path.join(root, file)
            if should_include_file(file_path):
                markdown_files.append(file_path)
    
    # カテゴリとファイル番号に基づいてソート
    return sorted(markdown_files, key=get_file_order)

def main():
    # ディレクトリパスの設定
    script_dir = get_script_dir()
    cline_dir = os.path.dirname(os.path.dirname(script_dir))  # .cline ディレクトリ
    roomodes_dir = os.path.join(cline_dir, 'roomodes')
    output_file = os.path.join(os.getcwd(), '.clinerules')

    # カスタムモードの処理
    roomodes = {
        'customModes': []
    }

    if os.path.exists(roomodes_dir):
        for file in os.listdir(roomodes_dir):
            if file.endswith('.md'):
                file_path = os.path.join(roomodes_dir, file)
                with open(file_path, 'r', encoding='utf-8') as f:
                    content = f.read()
                
                slug = os.path.splitext(file)[0]
                front_matter, body = parse_front_matter(content)
                
                mode_info = {
                    **front_matter,
                    'slug': slug,
                    'roleDefinition': body,
                    '__filename': file_path
                }
                roomodes['customModes'].append(mode_info)

    try:
        # Markdownファイルの収集
        files = collect_markdown_files(cline_dir)

        # 各ファイルの内容を結合
        contents = []
        current_category = None
        
        for file in files:
            # カテゴリの変更を検出
            category = next((p for p in file.split(os.sep) if p in get_category_order()), None)
            if category and category != current_category:
                current_category = category
                # カテゴリ見出しを追加
                contents.append(f"\n# {category.replace('_', ' ').title()}\n")
            
            # ファイルの内容を追加
            with open(file, 'r', encoding='utf-8') as f:
                content = f.read()
                # ファイル名から番号を除去してヘッダーを作成
                filename = os.path.basename(file)
                header = re.sub(r'^\d+_', '', filename[:-3])  # .mdを除去し、番号_を除去
                contents.append(f"\n## {header}\n")
                contents.append(content)

        # 結果の生成
        result = '\n'.join(contents)
        
        # カスタムモードの情報を追加
        if roomodes['customModes']:
            result += '\nこのプロジェクトには以下のモードが定義されています:'
            for mode in roomodes['customModes']:
                relative_path = os.path.relpath(
                    mode['__filename'],
                    os.getcwd()
                )
                result += f"\n- {mode['slug']} {mode.get('name', '')} at {relative_path}"

        # .roomodesファイルの生成
        roomodes_output = os.path.join(os.getcwd(), '.roomodes')
        with open(roomodes_output, 'w', encoding='utf-8') as f:
            json.dump(roomodes, f, ensure_ascii=False, indent=2)
        print(f"Generated .roomodes from {len(roomodes['customModes'])} mode files")

        # .clinerulesファイルの生成
        with open(output_file, 'w', encoding='utf-8') as f:
            f.write(result)
        print(f"Generated {output_file} from {len(files)} prompt files")

    except Exception as e:
        print(f"Error: {str(e)}", file=sys.stderr)
        sys.exit(1)

if __name__ == '__main__':
    main()
