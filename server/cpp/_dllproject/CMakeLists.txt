cmake_minimum_required(VERSION 4.2)
project(MinimalQtServer)

option(QT_LINK_RELATIVE "Link Qt libraries using a relative RPATH ($ORIGIN/qt on Linux)" OFF)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

add_compile_definitions(DLLPROJECT_EXPORTS)

set(SOURCES
    core/NativeImplCore.h
    core/NativeImplCore.cpp
    DirectExport.h
    DirectExport.cpp)

if (WIN32)
    list(APPEND SOURCES dllmain.cpp)
endif()

add_library(MinimalQtServer SHARED ${SOURCES})

if (QT_LINK_RELATIVE AND UNIX AND NOT APPLE)
    set_target_properties(MinimalQtServer PROPERTIES
        BUILD_WITH_INSTALL_RPATH TRUE
        INSTALL_RPATH "$ORIGIN/qt"
    )
endif()

# link to actual library implementation
add_subdirectory(../MinimalQtImpl ImplBuild)

target_link_libraries(MinimalQtServer PRIVATE MinimalQtImpl)
