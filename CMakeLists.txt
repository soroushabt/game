cmake_minimum_required(VERSION 3.16)

project(Game VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)





qt_standard_project_setup()

qt_add_executable(appGame
    main.cpp
    Shapegenerator.h Shapegenerator.cpp
    viewmodel.h viewmodel.cpp
    Shapes.h Shapes.cpp
)

qt_add_qml_module(appGame
    URI Game
    VERSION 1.0
    QML_FILES Main.qml
#    QML_FILES Myshapes.qml


)

set_target_properties(appGame PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appGame
    PRIVATE Qt6::Quick
)

install(TARGETS appGame
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
