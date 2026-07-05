#pragma once

#include "undirected_graph.hpp"

#include <unordered_map>
#include <vector>

bool findpath(const undirected_graph& t, int u, int v,
              std::unordered_map<int, bool>& visited,
              std::vector<int>& path);

std::vector<std::vector<int>>
get_fundamental_cycles_dfs(const undirected_graph& g);
