project(SDLTest CXX C)

set(App_SRCS
  app.cxx
  appInit.cxx
  appStart.cxx
)

add_library(App STATIC ${App_SRCS})

find_package(SDL2 REQUIRED)

target_include_directories(App PUBLIC
  ${SDLTest_INCLUDE_DIR}/libapp
  ${SDLTest_INCLUDE_DIR}/liberror
  ${SDL2_INCLUDE_DIR}
)

target_link_libraries(App
  ${SDL2_LIBRARY}
  Error
)

set_property(TARGET App PROPERTY CXX_STANDARD 11)
set_property(TARGET App PROPERTY CXX_STANDARD_REQUIRED ON)
