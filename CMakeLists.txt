cmake_minimum_required(VERSION 3.15)
project(cmake_translat-o-matic)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE headers
        "src/*.h"
)
file(GLOB_RECURSE sources
        "src/*.cpp"
)
add_library(${PROJECT_NAME} ${sources} ${headers})

set_target_properties(${PROJECT_NAME}
        PROPERTIES PUBLIC_HEADER "${headers}"
)

target_include_directories(${PROJECT_NAME} PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        "$<INSTALL_INTERFACE:$<INSTALL_PREFIX>/${CMAKE_INSTALL_INCLUDEDIR}>"
)

install(TARGETS ${LIBRARY_TARGET_NAME}
        EXPORT  ${PROJECT_NAME}
        LIBRARY       DESTINATION "${CMAKE_INSTALL_LIBDIR}"                            COMPONENT shlib
        ARCHIVE       DESTINATION "${CMAKE_INSTALL_LIBDIR}"                            COMPONENT lib
        RUNTIME       DESTINATION "${CMAKE_INSTALL_BINDIR}"                            COMPONENT bin
        PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${LIBRARY_TARGET_NAME}" COMPONENT dev
)