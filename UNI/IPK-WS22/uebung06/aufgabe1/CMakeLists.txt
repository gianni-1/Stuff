cmake_minimum_required(VERSION 3.11)

project(aufgabe1 LANGUAGES CXX)

add_library(pgm pgm.cc)
add_library(point point.cc)
add_library(canvas canvas.cc)

add_executable(plot plot.cc)

target_link_libraries(canvas PUBLIC pgm)
target_link_libraries(canvas PUBLIC point)
target_link_libraries(plot PUBLIC canvas)

