#pragma once

#include "undirected_graph.hpp"

#include <vector>

std::vector<int> dijkstra_path(const undirected_graph& g, int source, int target);
