cmake_minimum_required(VERSION 3.10)

set(project GPU_Gem)

project(${project})

add_subdirectory(${CMAKE_SOURCE_DIR}/glfw)
include_directories(${CMAKE_SOURCE_DIR}/
                    ${CMAKE_SOURCE_DIR}/include
)

# Add your source files
set(SOURCES
    ${CMAKE_SOURCE_DIR}/test/main.cpp
    ${CMAKE_SOURCE_DIR}/src/glad.c
)

# Add the executable
add_executable(${project} ${SOURCES})

target_link_libraries(${project} PRIVATE glfw)

# Optional: Set C++ standard
set_target_properties(${project} PROPERTIES CXX_STANDARD 17)

