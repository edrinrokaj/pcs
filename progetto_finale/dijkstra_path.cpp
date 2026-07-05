#include "dijkstra_path.hpp"

#include <algorithm>
#include <limits>
#include <queue>
#include <unordered_map>
#include <utility>

std::vector<int> dijkstra_path(const undirected_graph& g, int source, int target) {
    std::priority_queue<
        std::pair<int, int>,
        std::vector<std::pair<int, int>>,
        std::greater<std::pair<int, int>>
    > pq;

    std::unordered_map<int, int> dist;
    std::unordered_map<int, int> pred;

    for (auto& node : g.all_nodes()) {
        pred[node] = -1;
        dist[node] = std::numeric_limits<int>::max();
    }

    pred[source] = source;
    dist[source] = 0;
    pq.push(std::pair{0, source});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (u == target) {
            break;
        }
        if (d > dist[u]) {
            continue;
        } 
        for (auto& neighbour : g.neighbours(u)) {
            if (dist[u] != std::numeric_limits<int>::max() && dist[neighbour] > dist[u] + 1) {
                dist[neighbour] = dist[u] + 1;
                pred[neighbour] = u;
                pq.push(std::pair{dist[neighbour], neighbour});
            } 
        }  
    }

    std::vector<int> path;
    if (pred.find(target) == pred.end() || pred[target] == -1) {
        return path;
    }

    int node = target;
    while (node != source) {
        path.push_back(node);
        node = pred[node];
    }
    path.push_back(source);
    std::reverse(path.begin(), path.end());
    return path;
}
