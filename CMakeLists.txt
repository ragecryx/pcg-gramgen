cmake_minimum_required (VERSION 2.6)
project(PCGGram)

set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/DIST")
set(CMAKE_CXX_FLAGS "-std=c++11 -static-libstdc++ ${CMAKE_CXX_FLAGS}")


# Project Options/Settings

set(PCGGRAM_VERSION_MAJOR 0)
set(PCGGRAM_VERSION_MINOR 2)

option(BUILD_DEMO
    "Build the demo/example."
    ON
)

if(BUILD_DEMO)
    add_subdirectory(source_demo)
endif(BUILD_DEMO)



# Dependencies
# -



# Sources and Building

include_directories(
    "${PROJECT_SOURCE_DIR}/include"
)

file(GLOB SOURCEFILES
    "source/*.cpp"
)

add_library(PCGGram STATIC ${SOURCEFILES})



# Installation
install(TARGETS PCGGram DESTINATION lib)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/PCGGram DESTINATION include )

