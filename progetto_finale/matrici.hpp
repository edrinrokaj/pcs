#pragma once

#include "undirected_graph.hpp"

#include <Eigen/Dense>
#include <string>
#include <vector>

Eigen::MatrixXd build_incidence_matrix(const undirected_graph& g,
                                        bool use_de_pina = false);

Eigen::MatrixXd build_resistance_matrix(const undirected_graph& g);

Eigen::VectorXd build_generator_vector(const undirected_graph& g,
                                        bool use_de_pina = false);

std::vector<std::string> get_resistor_names(const undirected_graph& g);
