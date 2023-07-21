cmake_minimum_required(VERSION 3.11)

project(frequencies LANGUAGES CXX)

add_library(frequencies frequencies.cc)

add_executable(main main.cc)

target_link_libraries(main PUBLIC frequencies)
