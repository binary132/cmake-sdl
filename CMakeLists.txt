project(SDLTest CXX)

cmake_minimum_required(VERSION 2.8.12)

# global needed variables
set(SDLTest_PUBLIC_INCLUDE_DIRS
  ${CMAKE_SOURCE_DIR}/include
  CACHE INTERNAL "SDLTest public include directories"
)

set(SDLTest_LIB_DIRS
  ${CMAKE_SOURCE_DIR}/lib
  CACHE INTERNAL "SDLTest public include directories"
)

set(APPLICATION_NAME ${PROJECT_NAME})

set(APPLICATION_VERSION_MAJOR "0")
set(APPLICATION_VERSION_MINOR "0")
set(APPLICATION_VERSION_PATCH "1")

set(APPLICATION_VERSION	"${APPLICATION_VERSION_MAJOR}.${APPLICATION_VERSION_MINOR}.${APPLICATION_VERSION_PATCH}")

# where to look first for cmake modules, before ${CMAKE_ROOT}/Modules/ isinc
# checked
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/Modules)

# disallow in-source build
include(MacroEnsureOutOfSourceBuild)
macro_ensure_out_of_source_build("${PROJECT_NAME} requires an out of source build. Please create a separate build directory and run 'cmake /path/to/${PROJECT_NAME} [options]' there.")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/target)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

# find_package(SDL2 2.0.3)
# if(SDL2_FOUND)
#  target_include_directories(SDLUse PRIVATE ${SDL2_INCLUDE_DIRS})
#  target_link_libraries(SDLUse LINK_PRIVATE ${SDL2_LIBRARIES})
# endif()

include_directories(${SDLTest_PUBLIC_INCLUDE_DIRS})

add_subdirectory(include)
add_subdirectory(src)
