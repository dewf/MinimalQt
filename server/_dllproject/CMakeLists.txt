cmake_minimum_required(VERSION 4.2)
project(MinimalQtServer)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

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

# link to actual library implementation
# normally nativeimpl links to the .lib file directly, because the backend might not be C++
# but in this case we know it is
add_subdirectory(../cpp/MinimalQtImpl ${CMAKE_CURRENT_BINARY_DIR}/MinimalQtImpl)

target_link_libraries(MinimalQtServer PRIVATE MinimalQtImpl Qt6::Widgets)
