# CMake is case-nonsensitive for function, macros
# but case-sensitive for function arguments!
cmake_minimum_required(VERSION 3.15)

add_executable(lib_tests ut.cpp mockedTest.cpp)

# link our application with the library built
target_link_libraries(lib_tests awesomeLib)

# we have 4 libraries:
# gtest  - a googleTest library ( contains functions for unit test only)
# gmock  - a googleMock library ( contains functionality to mock methods for classes)
# gtest_main - a googleTest library with "main" function ( so we can just write test cases and don't think about main() )
# gmock_main - a googleMock library with "main" function ( so we can just write test cases and don't think about main() )
# So, please, be careful and either write your own main function in UT OR use ONE of *_main libraries.

target_link_libraries(lib_tests gtest gtest_main gmock)

add_test(testsInAwesomeLib lib_tests)