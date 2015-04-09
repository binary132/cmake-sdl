project(SDLTest CXX C)

set(App_SRCS
  app.cxx
)

add_library(App STATIC ${App_SRCS})

target_include_directories(App PUBLIC
  ${SDLTest_INCLUDE_DIR}/libapp
  ${SDLTest_INCLUDE_DIR}/liberror
)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})

target_link_libraries(App
  ${SDL2_LIBRARY}
  Error
)
