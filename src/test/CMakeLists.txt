project(test_dijkstra CXX)

cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "-Wall -std=c++14")

add_executable(test_dijkstra test_dijkstra.cpp)
add_executable(test_bellmanford test_bellmanford.cpp)
add_executable(test_johnson test_johnson.cpp)
add_executable(test_floyd test_floyd.cpp)