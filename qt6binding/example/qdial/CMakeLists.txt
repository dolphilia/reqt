cmake_minimum_required(VERSION 3.16)
project(qdial_example C)

add_executable(qdial_example
    main.c
)

target_link_libraries(qdial_example
    PRIVATE
        qt6binding
)
