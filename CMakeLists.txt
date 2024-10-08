cmake_minimum_required(VERSION 3.5)

project(mission-impossible VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        objects/baseobject.h objects/baseobject.cpp
        objects/positionable.h objects/positionable.cpp
        objects/human.h objects/human.cpp
        objects/monster.h objects/monster.cpp
        objects/commandcenter.h objects/commandcenter.cpp
        objects/movable.h objects/movable.cpp
        objects/obstacle.h objects/obstacle.cpp
        events/event.h events/event.cpp
        events/commandcentercommandevent.h events/commandcentercommandevent.cpp
        events/humanfoundevent.h events/humanfoundevent.cpp
        sprites/customgraphicsitem.h sprites/customgraphicsitem.cpp
        iloghandler.h iloghandler.cpp
        loghandler.h loghandler.cpp
        enums/gamemode.h
        gamestatemediator.h gamestatemediator.cpp
        gameview.h gameview.cpp
        gamemanager.h gamemanager.cpp
        gameoptions.h gameoptions.cpp
        point.h point.cpp
        utils.h utils.cpp
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        resources.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(mission-impossible
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET mission-impossible APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(mission-impossible SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(mission-impossible
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(mission-impossible PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(mission-impossible PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(mission-impossible)
endif()
