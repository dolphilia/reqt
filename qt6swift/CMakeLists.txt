cmake_minimum_required(VERSION 3.20)
project(qt6swift)

# Swift言語を有効化
enable_language(Swift)

# ライブラリのパスを設定
link_directories(
    ${PROJECT_SOURCE_DIR}/../qt6binding/build
)


# インクルードディレクトリを設定
include_directories(
    ${PROJECT_SOURCE_DIR}/../qt6binding/include
    ${PROJECT_SOURCE_DIR}/../qt6binding/include/qt6
)

# Swiftのコンパイルオプションを設定
set(CMAKE_Swift_FLAGS "${CMAKE_Swift_FLAGS} -import-objc-header ${CMAKE_SOURCE_DIR}/bridging-header.h")

# 実行ファイルを作成
add_executable(qt6swift
    src/main.swift
    #src/bridging-header.h
)

# Qt6バインディングライブラリをリンク
target_link_libraries(qt6swift qt6binding
)
