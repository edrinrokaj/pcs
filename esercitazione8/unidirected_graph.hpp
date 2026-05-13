#pragma once

#include "unidirected_edge.hpp"
#include <set>
#include <map>
#include <vector>

class unidirected_graph {
    std::set<unidirected_edge> edges_;
    std::map<int, std::set<int>> adj_;

public:
    unidirected_graph()
    {}
    unidirected_graph(const unidirected_graph& other)
        : edges_(other.edges_), adj_(other.adj_)
    {}

    std::set<int> neighbours(int node) const {
        return adj_.at(node);
    }

    void add_edge(int a, int b) {
        unidirected_edge e(a,b);
        edges_.insert(e);
        adj_[a].insert(b);
        adj_[b].insert(a);
    }
    

    std::set<unidirected_edge> all_edges() const {
        return edges_;
    }

    std::set<int> all_nodes() const {
        std::set<int> nodes;
        for (auto& [key, value] : adj_) {
            nodes.insert(key);
        }
        return nodes;
    }

    int edge_number(const unidirected_edge& e) const {
        int i = 0;
        for (auto& edge : edges_) {
            if (edge == e) {
                return i;
            }
            i++;
        }
        return -1;
    }

    unidirected_edge edge_at(int i) const {
        int j = 0;
        for (auto& edge : edges_) {
            if (j == i) {
                return edge; 
            }
            j++;
        }
        return unidirected_edge(-1, -1);
    }

    unidirected_graph operator-(const unidirected_graph& other) const {
        unidirected_graph difference;
        for (auto& edge : edges_) {
            if (other.edges_.count(edge) == 0) {
                difference.add_edge(edge.from(), edge.to());
            }
        }
        return difference;
    }

};