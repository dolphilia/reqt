cmake_minimum_required(VERSION 3.16)
project(qt6binding)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Find all header files in the source directories
file(GLOB_RECURSE MOC_HEADERS
    src/QtCore/*/*.h
    src/QtGui/*/*.h
    src/QtWidgets/*/*.h
)

# Find all source files in the source directories
file(GLOB_RECURSE SOURCE_FILES
    src/QtCore/*/*.cpp
    src/QtGui/*/*.cpp
    src/QtWidgets/*/*.cpp
)

add_library(qt6binding SHARED
    ${MOC_HEADERS}
    ${SOURCE_FILES}
)

target_include_directories(qt6binding PUBLIC include include/qt6 src src/QtCore src/QtGui src/QtWidgets)
target_link_libraries(qt6binding PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)

add_subdirectory(example)
add_subdirectory(demo)
