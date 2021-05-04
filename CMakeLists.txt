cmake_minimum_required(VERSION 3.10)

# set the project information
project(membrane VERSION 0.0.1)

# setup the C++ compiler
set(CMAKE_CPP_COMPILER g++)
set(CMAKE_CXX_STANDARD 13)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set C++ flags
set(CMAKE_CXX_FLAGS "-Wall -Wextra")

# get all C++ files
file(GLOB_RECURSE SOURCES *.cc)

# add the executable
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES} ${INCLUDE})
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 14)
