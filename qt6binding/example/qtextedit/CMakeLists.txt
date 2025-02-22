add_executable(qt6binding_qtextedit_example
    main.c
)

target_link_libraries(qt6binding_qtextedit_example
    PRIVATE
    qt6binding
    Qt6::Widgets
)
