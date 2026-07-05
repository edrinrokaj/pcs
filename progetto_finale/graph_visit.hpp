#pragma once

#include "undirected_graph.hpp"

#include <unordered_map>

// DFS con lifo<int>, BFS con fifo<int>.
template <typename Container>
undirected_graph graph_visit(const undirected_graph& g, int source, Container& c) {
    std::unordered_map<int, bool> reached;
    for (auto& node : g.all_nodes()) {
        reached[node] = false;
    }

    undirected_graph result;
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
