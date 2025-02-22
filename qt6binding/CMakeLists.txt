cmake_minimum_required(VERSION 3.16)
project(qt6binding)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Qt MOC headers
set(MOC_HEADERS
    include/handler_button_click.h
    include/handler_check_box.h
    include/handler_combo_box.h
    include/handler_date_edit.h
    include/handler_date_time_edit.h
    include/handler_dial.h
    include/handler_dock_widget.h
    include/handler_line_edit_text.h
    include/handler_list_view.h
    include/handler_mdi_area.h
    include/handler_mdi_sub_window.h
    include/handler_check_box.h
    include/handler_tab_bar.h
    include/handler_combo_box.h
    include/handler_date_edit.h
    include/handler_date_time_edit.h
    include/handler_dial.h
    include/handler_dock_widget.h
    include/handler_line_edit_text.h
    include/handler_mdi_area.h
    include/handler_mdi_sub_window.h
    include/bind_q_application.h
    include/bind_q_widget.h
    include/bind_q_push_button.h
    include/bind_q_line_edit.h
    include/bind_q_v_box_layout.h
    include/bind_q_h_box_layout.h
    include/bind_q_style.h
    include/bind_q_combo_box.h
    include/bind_q_label.h
    include/bind_q_check_box.h
    include/bind_q_date_edit.h
    include/bind_q_date_time_edit.h
    include/bind_q_dial.h
    include/bind_q_main_window.h
    include/bind_q_mdi_area.h
    include/bind_q_mdi_sub_window.h
    include/bind_q_dock_widget.h
    include/bind_q_status_bar.h
    include/bind_q_list_view.h
    include/bind_q_string_list_model.h
    include/handler_list_view.h
    include/bind_q_tab_bar.h
    include/bind_q_tab_widget.h
    include/handler_tab_widget.h
    include/bind_q_menu.h
    include/handler_menu.h
    include/bind_q_menu_bar.h
    include/handler_menu_bar.h
    include/bind_q_progress_bar.h
    include/handler_progress_bar.h
    include/bind_q_slider.h
    include/handler_slider.h
    include/bind_q_radio_button.h
    include/handler_radio_button.h
    include/bind_q_spin_box.h
    include/handler_spin_box.h
)

add_library(qt6binding SHARED
    ${MOC_HEADERS}
    src/bind_q_application.cpp
    src/bind_q_check_box.cpp
    src/bind_q_combo_box.cpp
    src/bind_q_date_edit.cpp
    src/bind_q_date_time_edit.cpp
    src/bind_q_dial.cpp
    src/bind_q_dock_widget.cpp
    src/bind_q_h_box_layout.cpp
    src/bind_q_label.cpp
    src/bind_q_line_edit.cpp
    src/bind_q_list_view.cpp
    src/bind_q_main_window.cpp
    src/bind_q_mdi_area.cpp
    src/bind_q_mdi_sub_window.cpp
    src/bind_q_push_button.cpp
    src/bind_q_status_bar.cpp
    src/bind_q_string_list_model.cpp
    src/bind_q_style.cpp
    src/bind_q_v_box_layout.cpp
    src/bind_q_widget.cpp
    src/c_q_application.cpp
    src/c_q_combo_box.cpp
    src/c_q_h_box_layout.cpp
    src/c_q_label.cpp
    src/c_q_list_view.cpp
    src/c_q_string_list_model.cpp
    src/c_q_style.cpp
    src/c_q_v_box_layout.cpp
    src/handler_button_click.cpp
    src/handler_check_box.cpp
    src/handler_combo_box.cpp
    src/handler_date_edit.cpp
    src/handler_date_time_edit.cpp
    src/handler_dial.cpp
    src/handler_dock_widget.cpp
    src/handler_line_edit_text.cpp
    src/handler_list_view.cpp
    src/handler_mdi_area.cpp
    src/handler_mdi_sub_window.cpp
    src/bind_q_tab_bar.cpp
    src/handler_tab_bar.cpp
    src/c_q_tab_bar.cpp
    src/bind_q_tab_widget.cpp
    src/handler_tab_widget.cpp
    src/c_q_tab_widget.cpp
    src/bind_q_menu.cpp
    src/handler_menu.cpp
    src/c_q_menu.cpp
    src/bind_q_menu_bar.cpp
    src/handler_menu_bar.cpp
    src/c_q_menu_bar.cpp
    src/bind_q_progress_bar.cpp
    src/handler_progress_bar.cpp
    src/c_q_progress_bar.cpp
    src/bind_q_slider.cpp
    src/handler_slider.cpp
    src/c_q_slider.cpp
    src/bind_q_radio_button.cpp
    src/handler_radio_button.cpp
    src/c_q_radio_button.cpp
    src/bind_q_spin_box.cpp
    src/handler_spin_box.cpp
    src/c_q_spin_box.cpp
)

target_include_directories(qt6binding PUBLIC include)
target_link_libraries(qt6binding PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)

add_subdirectory(example)
