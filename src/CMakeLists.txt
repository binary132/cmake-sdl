project(SDLTest CXX C)

add_subdirectory(lib)

set(main_SRCS
  main.cpp
)

add_executable(${APPLICATION_NAME} ${main_SRCS})

target_link_libraries(${APPLICATION_NAME} Hello)

find_package(SDL2 REQUIRED)

## using FindPkgConfig which doesn't work on Windows!(?)
#
# include(FindPkgConfig)

# pkg_search_module(SDL2 REQUIRED sdl2)
# pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

# include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
# target_link_libraries(${APPLICATION_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})

include_directories(${SDL2_INCLUDE_DIR}) # ${SDL2IMAGE_INCLUDE_DIR})
target_link_libraries(${APPLICATION_NAME} ${SDL2_LIBRARY}) # ${SDL2IMAGE_LIBRARIES})
