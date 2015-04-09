project(SDLTest CXX C)

set(Error_SRCS
  initError.cxx
)

add_library(Error STATIC ${Error_SRCS})

target_include_directories(Error PUBLIC
  ${SDLTest_INCLUDE_DIR}/liberror
)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})

target_link_libraries(Error
  ${SDL2_LIBRARY}
)
