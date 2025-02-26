add_executable(qt6binding_qobject_example
    main.c
)

target_link_libraries(qt6binding_qobject_example
    PRIVATE
    qt6binding
    Qt6::Core
    Qt6::Widgets
)