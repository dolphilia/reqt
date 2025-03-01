cmake_minimum_required(VERSION 3.27)
project(qt6binding_qinputdialog_example C)

add_executable(qt6binding_qinputdialog_example
    main.c
)

target_link_libraries(qt6binding_qinputdialog_example
    PRIVATE
    qt6binding
)
