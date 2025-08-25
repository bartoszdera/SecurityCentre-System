cmake_minimum_required(VERSION 3.5)

project(SecurityCentre VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        MainWindow.cpp
        MainWindow.h
        MainWindow.ui


        Model/rfidagent.h Model/rfidagent.cpp
        Model/facialrecognitionagent.h Model/facialrecognitionagent.cpp
        Model/fingerprintagent.h Model/fingerprintagent.cpp
        Model/Valid/validfacial.h Model/Valid/validfacial.cpp
        Model/Valid/validrfid.h Model/Valid/validrfid.cpp
        Model/Valid/validfingerprint.h Model/Valid/validfingerprint.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(SecurityCentre
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        simulator.h simulator.cpp simulator.ui
        AgentMgmntPanel.h AgentMgmntPanel.cpp AgentMgmntPanel.ui
        Model/ElectronicDevice.h Model/ElectronicDevice.cpp
        Model/DetectorDevice.h Model/DetectorDevice.cpp
        Model/AgentDevice.h Model/AgentDevice.cpp
        Model/validdata.h Model/validdata.cpp

        Model/Enum/accessresult.h
        Model/DeviceStorage.h Model/DeviceStorage.cpp
        Model/IValidData.h
        Model/ValidDataWrapper.h
        DetectorMgmntPanel.h DetectorMgmntPanel.cpp DetectorMgmntPanel.ui


)
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET SecurityCentre APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(SecurityCentre SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(SecurityCentre
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(SecurityCentre PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.SecurityCentre)
endif()
set_target_properties(SecurityCentre PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS SecurityCentre
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(SecurityCentre)
endif()
