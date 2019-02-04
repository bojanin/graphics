#Cmake file for lab 1

cmake_minimum_required(VERSION 2.8)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
project(Lab1)

file(GLOB_RECURSE lab1_sources "src/Lab1/sources/*.cpp")
file(GLOB_RECURSE lab1_headers "src/Lab1/headers/*.h")

add_executable(output ${lab1_sources})

target_include_directories(output PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/Lab1/headers)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(output ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
