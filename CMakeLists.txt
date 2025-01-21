cmake_minimum_required(VERSION 3.14)

set(CMAKE_C_COMPILER /usr/bin/clang)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(raytrace)
enable_testing()
# Specify the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)
cmake_policy(SET CMP0135 NEW)
# Pull Raylib using FetchContent
include(FetchContent)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG        master # Use latest version; replace with a specific tag if needed
)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(raylib)
FetchContent_MakeAvailable(googletest)

include_directories(src/utility)

set(SOURCES 
)

set(HEADERS
    src/img/ppm.hpp
    src/img/ray.hpp
    src/utility/vec3.hpp
    src/utility/color.hpp
)

# Add the executable for your project
add_executable(${PROJECT_NAME} src/main.cpp ${SOURCES} ${HEADERS})

# Link Raylib to your project
target_link_libraries(${PROJECT_NAME} raylib)

# Copy files over for testing
file(COPY test/test_files DESTINATION ${CMAKE_BINARY_DIR})

add_executable(
  rt_test
  test/ppm_test.cpp
  test/color_test.cpp
  test/vec3_test.cpp
  test/ray_test.cpp
  ${SOURCES}
)

target_include_directories(rt_test PRIVATE src/img src/utility)

target_link_libraries(
  rt_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(rt_test)
