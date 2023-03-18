cmake_minimum_required(VERSION 3.16)

project(SkeletonVizApp VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Core Gui OpenGL REQUIRED)
qt_standard_project_setup()

add_executable(SkeletonVizApp
    mainwindow.ui
    mainwindow.h
    mainwindow.cpp
    main.cpp
)

target_link_libraries(SkeletonVizApp PRIVATE Qt6::Core Qt6::Gui Qt6::OpenGL)

set_target_properties(SkeletonVizApp PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)