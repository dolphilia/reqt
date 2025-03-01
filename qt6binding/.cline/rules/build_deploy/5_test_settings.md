# テスト設定

## 5.1 テストの有効化
```cmake
# 1. テストの設定
enable_testing()
add_subdirectory(tests)

# 2. テストターゲットの定義
add_executable(${PROJECT_NAME}_test
    ${TEST_SOURCES}
)

# 3. テストの依存関係
target_link_libraries(${PROJECT_NAME}_test
    PRIVATE
        ${PROJECT_NAME}
        Qt6::Test
)
```

## 5.2 テストの実行
```cmake
# 1. テストケースの追加
add_test(NAME ${PROJECT_NAME}_test
         COMMAND ${PROJECT_NAME}_test)

# 2. テスト環境の設定
set_tests_properties(${PROJECT_NAME}_test
    PROPERTIES
        ENVIRONMENT "QT_QPA_PLATFORM=offscreen"
)

# 3. カバレッジの設定
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(${PROJECT_NAME}_test
        PRIVATE
            --coverage
    )
    target_link_options(${PROJECT_NAME}_test
        PRIVATE
            --coverage
    )
endif()
```

## 5.3 テスト設定のパターン

### 1. 単体テスト設定
```cmake
# 1. テストフレームワークの設定
find_package(GTest REQUIRED)
include(GoogleTest)

# 2. テストターゲットの作成
add_executable(unit_tests
    test_widget.cpp
    test_button.cpp
    test_dialog.cpp
)

# 3. テストのリンク設定
target_link_libraries(unit_tests
    PRIVATE
        ${PROJECT_NAME}
        GTest::GTest
        GTest::Main
)

# 4. テストの登録
gtest_discover_tests(unit_tests)
```

### 2. 統合テスト設定
```cmake
# 1. 統合テストの定義
add_executable(integration_tests
    test_widget_interaction.cpp
    test_dialog_flow.cpp
)

# 2. テスト依存関係の設定
target_link_libraries(integration_tests
    PRIVATE
        ${PROJECT_NAME}
        Qt6::Test
)

# 3. テスト環境の設定
set_tests_properties(integration_tests
    PROPERTIES
        ENVIRONMENT "QT_QPA_PLATFORM=offscreen"
)
```

## 5.4 テストスクリプト

### 1. テスト実行スクリプト
```cmake
# 1. テストスイートの実行
function(run_test_suite SUITE_NAME)
    add_custom_target(test_${SUITE_NAME}
        COMMAND ${CMAKE_CTEST_COMMAND}
            --output-on-failure
            --test-dir ${CMAKE_BINARY_DIR}
            -R ${SUITE_NAME}
    )
endfunction()

# 2. カバレッジレポートの生成
function(generate_coverage_report TARGET_NAME)
    add_custom_target(coverage_${TARGET_NAME}
        COMMAND lcov --capture
            --directory ${CMAKE_BINARY_DIR}
            --output-file coverage.info
        COMMAND genhtml coverage.info
            --output-directory coverage_report
    )
endfunction()
```

### 2. テスト環境設定スクリプト
```cmake
# 1. テストデータの準備
function(prepare_test_data TEST_NAME)
    add_custom_command(TARGET ${TEST_NAME}
        PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/test/data
            ${CMAKE_BINARY_DIR}/test/data
    )
endfunction()

# 2. テスト環境のクリーンアップ
function(cleanup_test_env TEST_NAME)
    add_custom_command(TARGET ${TEST_NAME}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E remove_directory
            ${CMAKE_BINARY_DIR}/test/data
    )
endfunction()
```

## 5.5 テスト設定のガイドライン

### 1. テスト構成
- 適切なテストフレームワークの選択
- テストケースの分類と整理
- テスト環境の設定
- カバレッジ測定の設定

### 2. テスト実行
- 自動テストの設定
- テスト結果の収集
- エラー報告の設定
- パフォーマンス測定

### 3. テストデータ
- テストデータの管理
- 環境の準備と後処理
- リソースの管理
- 一時ファイルの扱い

### 4. 品質管理
- カバレッジ目標の設定
- 性能要件の確認
- エラー検出の強化
- レポート生成の自動化
