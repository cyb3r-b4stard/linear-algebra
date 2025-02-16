cmake_minimum_required(VERSION 3.14.0)
project(LinearAlgebra VERSION 0.1.0 LANGUAGES CXX)

if(CMAKE_HOST_SYSTEM MATCHES LINUX)
    set(CMAKE_CXX_FLAGS -pthread)
endif()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall -Wextra")

include_directories(${PROJECT_SOURCE_DIR}/include)

set(HEADER_FILES
    include/matrix.h)

set(SOURCE_FILES
    src/matrix.cpp)

# add_library(LinearAlgebra ${SOURCE_FILES})

add_executable(main ${HEADER_FILES} ${SOURCE_FILES} ${PROJECT_SOURCE_DIR}/main.cpp)
# target_link_libraries(main PUBLIC LinearAlgebra)

### TESTING

# enable_testing()

# include(GoogleTest)
# include(FetchContent)

# For Windows: Prevent overriding the parent project's compiler/linker settings
# if(CMAKE_HOST_SYSTEM MATCHES WINDOWS)
    # set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# endif()

# FetchContent_Declare(
#     googletest
#     GIT_REPOSITORY https://github.com/google/googletest.git
#     GIT_TAG main
#     )
# FetchContent_MakeAvailable(googletest)

# add_executable(test ${HEADER_FILES} ${SOURCE_FILES} ${PROJECT_SOURCE_DIR}/test/test.cpp)
# target_link_directories(test PUBLIC ${SOURCE_FILES}/src)
# target_link_libraries(test GTest::gtest_main)
# gtest_discover_tests(test)

### BENCHMARKING

# set(BENCHMARK_ENABLE_TESTING NO)

# FetchContent_Declare(
#     googlebenchmark
#     GIT_REPOSITORY https://github.com/google/benchmark.git
#     GIT_TAG main
#     )
# FetchContent_MakeAvailable(googlebenchmark)

# add_executable(benchmark ${HEADER_FILES} ${SOURCE_FILES} ${PROJECT_SOURCE_DIR}/benchmark/benchmark.cpp)
# target_link_directories(benchmark ${SOURCE_FILES}/src)
# target_link_libraries(benchmark benchmark::benchmark_main)