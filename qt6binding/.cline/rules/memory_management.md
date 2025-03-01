# Qt6バインディングにおけるメモリ管理ガイド

このドキュメントでは、Qt6バインディングプロジェクトにおけるメモリ管理の規則を説明します。
詳細な内容は以下のセクションに分かれています：

1. [基本原則](memory_management/1_basic_principles.md)
   - 所有権の明確化
   - リソース管理の責任
   - 所有権の原則
   - リソース管理の原則
   - メモリ管理のガイドライン

2. [メモリ管理パターン](memory_management/2_memory_management_patterns.md)
   - スコープベースの管理
   - 参照カウント
   - スマートポインタパターン
   - メモリプールパターン
   - メモリ管理パターンのガイドライン

3. [Qt特有のメモリ管理](memory_management/3_qt_specific_memory_management.md)
   - 親子関係の管理
   - Qtのスマートポインタ
   - Qt特有のメモリ管理パターン
   - メモリ管理の実装例
   - メモリ管理のガイドライン

4. [C APIのメモリ管理](memory_management/4_c_api_memory_management.md)
   - リソース作成/削除
   - 一時リソースの管理
   - リソース管理パターン
   - メモリ管理の実装例
   - メモリ管理のガイドライン

5. [メモリリーク防止](memory_management/5_memory_leak_prevention.md)
   - リソーストラッキング
   - デバッグ支援
   - リソース監視システム
   - メモリリーク検出
   - メモリリーク防止のガイドライン
