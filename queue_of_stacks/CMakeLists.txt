cmake_minimum_required(VERSION 3.22.1)
project(queue_of_stacks CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-g -O0 --coverage -fprofile-arcs -ftest-coverage")

project(${PROJECT_NAME} VERSION 1.0)

file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "src/*.cpp")
file(GLOB_RECURSE PROJECT_TESTS CONFIGURE_DEPENDS "tests/*.cpp")

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

include(CTest)
enable_testing()

# Link runTests with what we want to test and the GTest and pthread library
add_executable(tests ${PROJECT_TESTS})
target_include_directories(tests PRIVATE "inc")
add_compile_definitions()
target_link_libraries(tests ${GTEST_LIBRARIES} pthread)
gtest_discover_tests(tests)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
set(COVERAGE_EXCLUDES "/usr/include/\\*;${CMAKE_SOURCE_DIR}/src/main.cpp;")
include(CodeCoverage)
setup_target_for_coverage(NAME coverage EXECUTABLE ctest DEPENDENCIES coverage)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE "inc")