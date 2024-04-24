cmake_minimum_required(VERSION 3.10)
project(example)

# run example
add_executable(MainMenu MainMenu.cpp)

# Includes
target_include_directories(MainMenu PUBLIC ../include)

# sources
add_subdirectory(../src)
