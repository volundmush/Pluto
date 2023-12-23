cmake_minimum_required(VERSION 3.22)

project(pluto)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOUP_INCLUDE include/*.h include/*.hpp)
file(GLOB_RECURSE SOUP_SRC src/*.cpp src/*.c)

set(SOUP_INCLUDE_DIRS
        include
)

add_library(soupintrin STATIC Intrin/sha256_transform_intrin.cpp)

add_library(soup STATIC ${SOUP_INCLUDE} ${SOUP_SRC})
target_include_directories(soup PUBLIC ${SOUP_INCLUDE_DIRS})


