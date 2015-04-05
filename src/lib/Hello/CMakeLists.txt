project(SDLTest CXX)

set(Hello_SRCS
  hello.cpp
)

add_library(Hello STATIC ${Hello_SRCS})
target_include_directories(Hello PUBLIC ${SDLTest_INCLUDE_DIR}/libhello)
