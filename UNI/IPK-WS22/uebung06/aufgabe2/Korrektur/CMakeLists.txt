cmake_minimum_required(VERSION 3.11)

project(uebung06 LANGUAGES CXX)

add_library(point point.cc)

add_executable(main main.cc)
add_executable(analyse_tool analyse.cc point.hh)

target_link_libraries(main PUBLIC point)

