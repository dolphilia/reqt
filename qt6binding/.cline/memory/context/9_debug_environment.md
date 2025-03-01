# デバッグ環境

## 7.1 必要なツール
- GDB/LLDB
- Qt Creator
- Visual Studio（Windows）

## 7.2 デバッグ設定
```cmake
# デバッグビルド
set(CMAKE_BUILD_TYPE Debug)

# デバッグ情報の生成
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
```

## 7.3 デバッグ機能
1. ブレークポイント
   - コード内の任意の位置
   - 条件付きブレークポイント
   - データブレークポイント

2. 変数監視
   - ローカル変数
   - メンバ変数
   - スタックトレース

3. メモリ分析
   - メモリリーク検出
   - 未初期化変数の検出
   - バッファオーバーフロー検出
