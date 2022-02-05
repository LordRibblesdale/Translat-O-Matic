cmake_minimum_required(VERSION 3.15)
project(translat-o-matic)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

file(GLOB_RECURSE headers
        "include/*.hpp"
)
file(GLOB_RECURSE sources
        "src/*.cpp"
)
file(GLOB_RECURSE test "test/main.cpp")

add_library(${PROJECT_NAME}_static STATIC ${sources})
add_library(${PROJECT_NAME}_shared SHARED ${sources})
add_executable(${PROJECT_NAME} ${test} ${sources} ${headers})