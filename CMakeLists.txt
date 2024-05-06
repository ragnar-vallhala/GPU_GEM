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
    ${CMAKE_SOURCE_DIR}/src/imgui_demo.cpp
    ${CMAKE_SOURCE_DIR}/src/imgui_draw.cpp
    ${CMAKE_SOURCE_DIR}/src/imgui_impl_glfw.cpp
    ${CMAKE_SOURCE_DIR}/src/imgui_impl_opengl3.cpp
    ${CMAKE_SOURCE_DIR}/src/imgui_tables.cpp
    ${CMAKE_SOURCE_DIR}/src/imgui_widgets.cpp
    ${CMAKE_SOURCE_DIR}/src/imgui.cpp
)



# Add the executable
add_executable(${project} ${SOURCES})

#target_include_directories(${project})

target_link_libraries(${project} PRIVATE glfw opengl32.lib)
#target_link_directories(${project} PRIVATE libs/lib-vc2010-64)
set_target_properties(${project} PROPERTIES CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

