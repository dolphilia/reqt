cmake_minimum_required(VERSION 3.16)

# QVariantサンプルプログラム
add_executable(qt6binding_qvariant_example main.c)
target_link_libraries(qt6binding_qvariant_example PRIVATE qt6binding)
