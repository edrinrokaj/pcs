#pragma once

#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
#include "unidirected_graph.hpp"

unidirected_graph dijkstra(const unidirected_graph& g, int source) {
    
    std::priority_queue<
        std::pair<int, int>, 
        std::vector<std::pair<int, int>>, 
        std::greater<std::pair<int, int>>
    > pq;
    
    std::unordered_map<int, int> dist;
    std::unordered_map<int, int> pred;
    
    for (auto& node : g.all_nodes()) {
        pred[node] = -1;
        dist[node] = 1000000;
    }
    
    pred[source] = source;
    dist[source] = 0;
    
    for (auto& node : g.all_nodes()) {
        pq.push(std::pair{dist[node], node});
    }
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) {
            continue;
        }
        for (auto& neighbour : g.neighbours(u)) {
            if (dist[neighbour] > dist[u] + 1) {
                dist[neighbour] = dist[u] + 1;
                pred[neighbour] = u;
                pq.push(std::pair{dist[neighbour], neighbour});
            } 
        }  
    }
   
    unidirected_graph graph;
    for (auto& node : g.all_nodes()) {
        if (node != source && pred[node] != -1) {
            graph.add_edge(pred[node], node);
        }
    }
    return graph;
}





