cmake_minimum_required(VERSION 3.16)

add_executable(qt6binding_qtimer_example main.c)
target_link_libraries(qt6binding_qtimer_example PRIVATE qt6binding)
