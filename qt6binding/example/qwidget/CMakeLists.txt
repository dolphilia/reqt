cmake_minimum_required(VERSION 3.16)
project(qt6binding_qwidget_example VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 親ディレクトリのlibqt6bindingをリンク
add_executable(qt6binding_qwidget_example
    main.c
)

target_link_libraries(qt6binding_qwidget_example
    PRIVATE
        qt6binding
)

# インクルードディレクトリの設定
target_include_directories(qt6binding_qwidget_example
    PRIVATE
        ${CMAKE_SOURCE_DIR}/../../include
)
