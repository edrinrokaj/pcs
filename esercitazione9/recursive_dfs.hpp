#pragma once

#include "unidirected_graph.hpp"
#include <unordered_map>

void recursive_dfs_helper(const unidirected_graph& g, 
    int node, 
    std::unordered_map<int, bool>& reached,
    unidirected_graph& result) 
    {
        for (auto& neighbour : g.neighbours(node)) {
            if (!reached[neighbour]) {
                reached[neighbour] = true;
                result.add_edge(node, neighbour);
                recursive_dfs_helper(g, neighbour, reached, result);
            } 
        }
    }

unidirected_graph recursive_dfs(const unidirected_graph& g, int source) {
    std::unordered_map<int, bool> reached;
    for (auto& node : g.all_nodes()) {
        reached[node] = false;
    }
    unidirected_graph result;
    reached[source] = true;
    recursive_dfs_helper(g, source, reached, result);
    return result;
}