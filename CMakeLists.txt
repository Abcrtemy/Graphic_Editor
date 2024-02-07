cmake_minimum_required(VERSION 3.5)

project(Graphics_editor VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        View/form.cpp
        View/form.h
        View/form.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Graphics_editor
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        Model/painter.h Model/painter.cpp
        Model/figure.h Model/figure.cpp
        Model/proplist.h Model/proplist.cpp
        Model/setofprops.h Model/setofprops.cpp
        Model/frame.h Model/frame.cpp
        Model/group.h Model/group.cpp
        Model/grobject.h Model/grobject.cpp
        Controller/controller.h Controller/controller.cpp
        Model/model.h Model/model.cpp
        Model/factory.h Model/factory.cpp
        Model/objectstore.h Model/objectstore.cpp
        Model/scene.h Model/scene.cpp
        Model/paintcontroller.h Model/paintcontroller.cpp
        Model/Selection/selectiondealler.h Model/Selection/selectiondealler.cpp

        Controller/action.h Controller/action.cpp
        View/graphicsscene.h View/graphicsscene.cpp

        Controller/state.h Controller/state.cpp
        Controller/statecollection.h Controller/statecollection.cpp
        Model/Selection/selectionstore.h Model/Selection/selectionstore.cpp
        Model/propdealer.h Model/propdealer.cpp
        Model/Selection/selection.h Model/Selection/selection.cpp
        Model/groupdealler.h Model/groupdealler.cpp
        Model/Change/change.h Model/Change/change.cpp
        Model/Change/changestore.h Model/Change/changestore.cpp
        Model/Change/changedealler.h Model/Change/changedealler.cpp
#        Model/selectiondealler.h Model/selectiondealler.cpp


    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Graphics_editor APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Graphics_editor SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Graphics_editor
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Graphics_editor PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Graphics_editor)
endif()
set_target_properties(Graphics_editor PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Graphics_editor
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Graphics_editor)
endif()
