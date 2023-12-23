cmake_minimum_required(VERSION 3.22)

project(soup)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(vendor/Soup)

file(GLOB_RECURSE PLUTO_INCLUDE include/*.h include/*.hpp)
file(GLOB_RECURSE PLUTO_SRC src/*.cpp src/*.c)

set(PLUTO_INCLUDE_DIRS
        include/pluto
        vendor/Soup/include
)

add_library(pluto STATIC ${PLUTO_INCLUDE} ${PLUTO_SRC})
target_include_directories(pluto PUBLIC ${PLUTO_INCLUDE_DIRS} ${SOUP_INCLUDE_DIRS})
target_link_libraries(pluto soup)

add_executable(pluto_exec apps/pluto.cpp)
target_include_directories(pluto_exec PUBLIC ${PLUTO_INCLUDE_DIRS} ${SOUP_INCLUDE_DIRS})
target_link_libraries(pluto_exec pluto)
set_target_properties(pluto_exec PROPERTIES OUTPUT_NAME pluto)

