#pragma once

#include "unidirected_graph.hpp"
#include <unordered_map>

template <typename Container>
unidirected_graph graph_visit(const unidirected_graph& g, int source, Container& c) {
    std::unordered_map<int, bool> reached;
    for (auto& node : g.all_nodes()) {
        reached[node] = false;
    }
    unidirected_graph result;
    c.put(source);
    reached[source] = true;
    while (!c.empty()) {
        int u = c.get();
        for (auto& neighbour : g.neighbours(u)) {
            if (!reached[neighbour]) {
                reached[neighbour] = true;
                result.add_edge(u, neighbour);
                c.put(neighbour);
            } 
        }
    }
    return result;
}