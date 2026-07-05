cmake_minimum_required(VERSION 3.20)
project(progetto_finale)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

find_package(Eigen3 REQUIRED)

set(SOURCES
    parser_netlist.cpp
    metodo_dfs.cpp
    depina_min_cycles.cpp
    dijkstra_path.cpp
    matrici.cpp
    linear_solver.cpp
    circuit_solver.cpp
)

add_executable(main_circuit main.cpp ${SOURCES})
target_link_libraries(main_circuit Eigen3::Eigen)

add_executable(test_output test_output.cpp ${SOURCES})
target_link_libraries(test_output Eigen3::Eigen)

add_test(NAME test_output COMMAND test_output ${CMAKE_CURRENT_SOURCE_DIR}/netlist.txt)

enable_testing()