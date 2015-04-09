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

# find_package(SDL2 REQUIRED)

# include_directories(${SDL2_INCLUDE_DIR}) # ${SDL2IMAGE_INCLUDE_DIR})
# target_link_libraries(${APPLICATION_NAME} ${SDL2_LIBRARY}) # ${SDL2IMAGE_LIBRARIES})

# target_compile_features(${APPLICATION_NAME} PRIVATE cxx_range_for)
# add_definitions("-std=c++11")
