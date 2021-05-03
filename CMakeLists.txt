cmake_minimum_required(VERSION 3.15)
project(cmake_translat-o-matic)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE headers
        "include/*.h"
)
file(GLOB_RECURSE sources
        "src/*.cpp"
)

add_executable(${PROJECT_NAME} ${sources} ${headers})