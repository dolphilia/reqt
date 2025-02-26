cmake_minimum_required(VERSION 3.16)

# QStringサンプルプログラム
add_executable(qt6binding_qstring_example main.c)
target_link_libraries(qt6binding_qstring_example PRIVATE qt6binding)
