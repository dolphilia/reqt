cmake_minimum_required(VERSION 3.16)
project(qplaintextedit_example C)

add_executable(qplaintextedit_example
    main.c
)

target_link_libraries(qplaintextedit_example
    PRIVATE
        qt6binding
)
