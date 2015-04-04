project(1 CXX)

set(Hello_SHARED_LIB Hello)

set(Hello_SRCS
  hello.cpp
)

add_library (${Hello_SHARED_LIB} SHARED ${Hello_SRCS})
