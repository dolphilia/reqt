cmake_minimum_required(VERSION 3.16)
project(qt6binding_qmdi_example VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 実行ファイルの作成
add_executable(qt6binding_qmdi_example
    main.c
)

# qt6bindingライブラリのリンク
target_link_libraries(qt6binding_qmdi_example
    PRIVATE
        qt6binding
)

# インクルードディレクトリの設定
target_include_directories(qt6binding_qmdi_example
    PRIVATE
        ${CMAKE_SOURCE_DIR}/../../include
)
