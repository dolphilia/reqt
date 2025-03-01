# バージョニング規則

## 1.1 セマンティックバージョニング
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

## 1.2 バージョン管理ファイル
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

## 1.3 バージョン管理パターン

### 1. バージョン情報の定義
```cpp
// version.h.in
#define QT6BINDING_VERSION_MAJOR @QT6BINDING_VERSION_MAJOR@
#define QT6BINDING_VERSION_MINOR @QT6BINDING_VERSION_MINOR@
#define QT6BINDING_VERSION_PATCH @QT6BINDING_VERSION_PATCH@
#define QT6BINDING_VERSION "@QT6BINDING_VERSION@"

// バージョン文字列の生成
#define QT6BINDING_VERSION_STR \
    QT6BINDING_VERSION " (" __DATE__ " " __TIME__ ")"

// バージョン番号の生成
#define QT6BINDING_VERSION_NUMBER \
    ((QT6BINDING_VERSION_MAJOR << 16) | \
     (QT6BINDING_VERSION_MINOR << 8) | \
     (QT6BINDING_VERSION_PATCH))
```

### 2. バージョン情報の利用
```cpp
// バージョン情報の取得
const char* get_version() {
    return QT6BINDING_VERSION;
}

// バージョン番号の比較
bool is_version_compatible(int required_version) {
    return QT6BINDING_VERSION_NUMBER >= required_version;
}

// バージョン文字列の取得
const char* get_version_string() {
    return QT6BINDING_VERSION_STR;
}
```

## 1.4 バージョン管理スクリプト

### 1. バージョン更新スクリプト
```python
#!/usr/bin/env python3
import re
import sys

def update_version(version_file, new_version):
    major, minor, patch = map(int, new_version.split('.'))
    
    with open(version_file, 'r') as f:
        content = f.read()
    
    content = re.sub(
        r'set\(QT6BINDING_VERSION_MAJOR \d+\)',
        f'set(QT6BINDING_VERSION_MAJOR {major})',
        content
    )
    content = re.sub(
        r'set\(QT6BINDING_VERSION_MINOR \d+\)',
        f'set(QT6BINDING_VERSION_MINOR {minor})',
        content
    )
    content = re.sub(
        r'set\(QT6BINDING_VERSION_PATCH \d+\)',
        f'set(QT6BINDING_VERSION_PATCH {patch})',
        content
    )
    
    with open(version_file, 'w') as f:
        f.write(content)
```

### 2. バージョン検証スクリプト
```python
#!/usr/bin/env python3
import re
import sys

def validate_version(version):
    if not re.match(r'^\d+\.\d+\.\d+$', version):
        return False
    
    major, minor, patch = map(int, version.split('.'))
    
    # バージョン番号の範囲チェック
    if not (0 <= major <= 99 and
            0 <= minor <= 99 and
            0 <= patch <= 99):
        return False
    
    return True
```

## 1.5 バージョニングのガイドライン

### 1. バージョン番号の選択
- 破壊的変更の判断基準
- 機能追加の基準
- バグ修正の基準
- プレリリースの扱い

### 2. バージョン管理
- バージョン情報の一元管理
- 更新手順の標準化
- 変更履歴の管理
- 互換性の確保

### 3. リリース管理
- リリースタグの付け方
- ブランチ戦略との連携
- バージョン更新の自動化
- リリースノートの作成

### 4. 互換性管理
- APIの互換性維持
- ABI互換性の確保
- 後方互換性のテスト
- 非互換変更の告知
