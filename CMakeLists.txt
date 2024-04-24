cmake_minimum_required(VERSION 3.10)
project(my_project)

# All src directory src/
file(GLOB SOURCES "src/*.cpp")

# Main Menu
add_executable(my_project ${SOURCES})

# headers
target_include_directories(my_project PUBLIC include)
