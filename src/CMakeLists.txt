# project(SDLTest CXX)

find_library(Hello_SHARED_LIB Hello ${SDLTest_LIB_DIRS})

set(main_SRCS
  main.cpp
)

add_executable(${APPLICATION_NAME} ${main_SRCS})
target_link_libraries(${APPLICATION_NAME} ${Hello_SHARED_LIB})
