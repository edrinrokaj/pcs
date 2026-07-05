#pragma once

#include "components.hpp"

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

class undirected_edge {
    int from_;
    int to_;

public:
    undirected_edge(int a, int b)
        : from_(std::min(a, b)), to_(std::max(a, b)) {}

    int from() const { return from_; }
    int to()   const { return to_; }

    bool operator==(const undirected_edge& other) const {
        return from_ == other.from_ && to_ == other.to_;
    }
    bool operator<(const undirected_edge& other) const {
        if (from_ != other.from_) {
            return from_ < other.from_;
        }
        return to_ < other.to_;
    }
};

inline std::ostream& operator<<(std::ostream& os, const undirected_edge& e) {
    os << "(" << e.from() << ", " << e.to() << ")";
    return os;
}

struct ComponentEdge {
    undirected_edge edge;
    Component component;

    int from() const { 
        return edge.from(); 
    }
    int to() const { 
        return edge.to(); 
    }
    const Component& comp() const { 
        return component; 
    }
};

class undirected_graph {
    std::set<undirected_edge> edges_;
    std::map<int, std::set<int>> adj_;
    std::map<undirected_edge, Component> components_;

public:
    undirected_graph()
    {}

    undirected_graph(const undirected_graph& other)
        : edges_(other.edges_),
          adj_(other.adj_),
          components_(other.components_)
    {}

    void add_edge(int a, int b) {
        undirected_edge e(a, b);
        edges_.insert(e);
        adj_[a].insert(b);
        adj_[b].insert(a);
    }

    void add_component(int a, int b, const Component& c) {
        add_edge(a, b);
        components_[undirected_edge(a, b)] = c;
    }

    std::set<int> neighbours(int node) const {
        auto it = adj_.find(node);
        if (it == adj_.end()) {
            return {};
        } 
        return it->second;
    }

    std::set<undirected_edge> all_edges() const {
        return edges_;  
    }
        

    std::set<int> all_nodes() const {
        std::set<int> nodes;
        for (auto& [key, value] : adj_) {
            nodes.insert(key);
        }
        return nodes;
    }

    int edge_number(const undirected_edge& e) const {
        int i = 0;
        for (auto& edge : edges_) {
            if (edge == e) {
                return i; 
            }
            i++;
        }
        return -1;
    }

    std::vector<ComponentEdge> all_component_edges(char type) const {
        std::vector<ComponentEdge> out;
        for (auto& [edge, comp] : components_) {
            if (comp.type == type) {
                out.push_back({edge, comp});
            }
        }
        return out;
    }

    undirected_graph operator-(const undirected_graph& other) const {
        undirected_graph diff;
        for (auto& edge : edges_) {
            if (other.edges_.count(edge) == 0) {
                diff.add_edge(edge.from(), edge.to());
            }
        }
        return diff;
    }
};
