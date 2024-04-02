cmake_minimum_required(VERSION 3.0)

project(SOLDIERFIRE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGHS} -g -Wall -std=c++11")

# set(CMAKE_BUILD_TYPE Debug) 这样就不需要写 -g 了

# include_directories(./include)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(procmake main.cpp src/gun.cpp src/soldier.cpp)

