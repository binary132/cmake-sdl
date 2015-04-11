project(SDLTest CXX C)

cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

# global variables
set(SDLTest_INCLUDE_DIR
  ${CMAKE_SOURCE_DIR}/include
)

set(SDLTest_TARGET_DIR
  ${CMAKE_BINARY_DIR}/target
)

set(SDLTest_LIB_DIR
  ${CMAKE_BINARY_DIR}/lib
)

set(APPLICATION_NAME ${PROJECT_NAME})

# where to look first for cmake modules, before ${CMAKE_ROOT}/Modules/ is checked
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/Modules)

# disallow in-source build
include(MacroEnsureOutOfSourceBuild)
macro_ensure_out_of_source_build("${PROJECT_NAME} requires an out of source build. Please create a separate build directory and run 'cmake /path/to/${PROJECT_NAME} [options]' there.")

# Define output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SDLTest_TARGET_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SDLTest_LIB_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${SDLTest_LIB_DIR})

add_subdirectory(src)
