#pragma once

#include "undirected_graph.hpp"

#include <vector>

std::vector<std::vector<int>>
get_fundamental_cycles_dePina(const undirected_graph& g);
