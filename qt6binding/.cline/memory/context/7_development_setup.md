# 開発環境セットアップ

## 5.1 必要なツール
1. CMake (>= 3.16)
2. Qt6開発環境
3. C++17対応コンパイラ
4. ビルドツール（Make/Ninja）

## 5.2 環境変数
```bash
# Qt6のパス
export Qt6_DIR=/path/to/qt6

# ビルドツール
export CMAKE_GENERATOR=Ninja  # 推奨
```

## 5.3 ビルド手順
```bash
# ビルドディレクトリの作成
mkdir build && cd build

# CMakeの設定
cmake ..

# ビルドの実行
cmake --build .
