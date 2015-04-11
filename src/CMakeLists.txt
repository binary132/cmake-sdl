project(SDLTest CXX C)

add_subdirectory(lib)

set(main_SRCS
  main.cxx
)

add_executable(${APPLICATION_NAME} ${main_SRCS})

target_link_libraries(${APPLICATION_NAME}
  App
  Error
)

set_property(TARGET ${APPLICATION_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${APPLICATION_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)