#Cmake file for lab 7

cmake_minimum_required(VERSION 3.1)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
project(lab6)

file(GLOB_RECURSE lab7_sources "source/*.cpp")

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(glm REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )
add_executable(output ${lab7_sources})


target_include_directories(output PRIVATE glm)
target_include_directories(output PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/source/headers/)
target_link_libraries(output ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
target_link_libraries(output glm)
