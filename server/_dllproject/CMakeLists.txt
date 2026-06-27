cmake_minimum_required(VERSION 3.22)
project(MinimalQtServer)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN YES)

#find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

set(SOURCES
    core/NativeImplCore.h
    core/NativeImplCore.cpp
    DirectExport.h
    DirectExport.cpp)

if (WIN32)
    list(APPEND SOURCES dllmain.cpp)
endif()

#add_library(MinimalQtServer SHARED ${SOURCES})
qt_add_library(MinimalQtServer SHARED ${SOURCES})

# link to actual library implementation
# normally nativeimpl links to the .lib file directly, because the backend might not be C++
# but in this case we know it is
add_subdirectory(../cpp/MinimalQtImpl ${CMAKE_CURRENT_BINARY_DIR}/MinimalQtImpl)

target_link_libraries(MinimalQtServer PRIVATE MinimalQtImpl Qt6::Widgets)

set_target_properties(MinimalQtServer PROPERTIES
        BUILD_RPATH "$ORIGIN/qt/lib"
        INSTALL_RPATH "$ORIGIN/qt/lib"
)

# install stuff ==================================
# Install the executable to "${CMAKE_INSTALL_PREFIX}/bin".
install(TARGETS MinimalQtServer
        BUNDLE  DESTINATION .
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Generate the deployment script for MyApp.
qt_generate_deploy_app_script(
        TARGET MinimalQtServer
        OUTPUT_SCRIPT deploy_script
        NO_UNSUPPORTED_PLATFORM_ERROR
        NO_TRANSLATIONS
)

# Run the deployment script during installation (on "cmake --install").
install(SCRIPT ${deploy_script})
