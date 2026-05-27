cmake_minimum_required(VERSION 3.10)
project(esercitazione10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")
find_package(Eigen3 REQUIRED)
add_executable(test_gradient test_gradient.cpp)
target_link_libraries(test_gradient Eigen3::Eigen)
add_test(NAME test_gradient COMMAND test_gradient)

enable_testing()

