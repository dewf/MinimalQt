cmake_minimum_required(VERSION 4.2)
project(MinimalQtServer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

#set(CMAKE_AUTOUIC ON)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(SOURCES
    core/NativeImplCore.h
    core/NativeImplCore.cpp
    DirectExport.h
    DirectExport.cpp)

if (WIN32)
    list(APPEND SOURCES dllmain.cpp)
endif()

add_library(MinimalQtServer SHARED ${SOURCES})

# link to actual library implementation
add_library(MinimalQtImpl STATIC IMPORTED GLOBAL)
set_target_properties(MinimalQtImpl PROPERTIES
        IMPORTED_LOCATION_DEBUG
        "${CMAKE_CURRENT_SOURCE_DIR}/../cpp/MinimalQtImpl/cmake-build-debug/MinimalQtImpl.lib"

        IMPORTED_LOCATION_RELEASE
        "${CMAKE_CURRENT_SOURCE_DIR}/../cpp/MinimalQtImpl/cmake-build-release/MinimalQtImpl.lib"

        MAP_IMPORTED_CONFIG_RELWITHDEBINFO Release
        MAP_IMPORTED_CONFIG_MINSIZEREL Release
)
target_link_libraries(MinimalQtServer PRIVATE MinimalQtImpl Qt${QT_VERSION_MAJOR}::Widgets)
