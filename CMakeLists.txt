cmake_minimum_required(VERSION 3.16)

project(Voyage-widget VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

add_executable(Voyage-widget)

#add_library(Voyage-lib "")

target_sources(Voyage-widget
    PRIVATE
        main.cpp
        mainwindow.cpp
        mainwindow.h
        renderarea.cpp
        renderarea.h
)
target_include_directories(Voyage-widget PRIVATE "${PROJECT_SOURCE_DIR}")

add_subdirectory(celestial_body)

target_link_libraries(Voyage-widget PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(Voyage-widget PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS Voyage-widget
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

#if(QT_VERSION_MAJOR EQUAL 6)
#    qt_finalize_executable(Voyage-widget)
#endif()
