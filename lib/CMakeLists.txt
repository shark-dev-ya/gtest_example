# CMake is case-nonsensitive for function, macros
# but case-sensitive for function arguments!
cmake_minimum_required(VERSION 3.15)

#more information might be found: https://cmake.org/cmake/help/latest/command/project.html#command:project 
project(awesomeLib LANGUAGES CXX)

# let's set standard used  to C++17
set(CMAKE_CXX_STANDARD 17)

# we can have variables here also!
set(source_files 
    src/awesomeLib.cpp
    src/ButtonDispatcher.cpp
    src/ConsoleButtonHandler.cpp
)

# and we tell to CMake to build executable file:
add_library(awesomeLib STATIC ${source_files})

target_include_directories(awesomeLib PUBLIC include)

add_subdirectory(ut)