# CMake is case-nonsensitive for function, macros
# but case-sensitive for function arguments!
cmake_minimum_required(VERSION 3.15)

#more information might be found: https://cmake.org/cmake/help/latest/command/project.html#command:project 
project(NotHelloWorld LANGUAGES CXX)

# let's set standard used  to C++17
set(CMAKE_CXX_STANDARD 17)

# we can have variables here also!
set(source_files    src/main.cpp    )

# and we tell to CMake to build executable file:
add_executable(myAwesomeApp ${source_files})

# link our application with the library built
target_link_libraries(myAwesomeApp awesomeLib)

# target_include_directories(myAwesomeApp INTERFACE $<TARGET_PROPERTY:awesomeLib,INCLUDE_DIRECTORIES> )