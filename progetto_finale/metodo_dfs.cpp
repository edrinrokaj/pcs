#include "metodo_dfs.hpp"

#include "containers.hpp"
#include "graph_visit.hpp"

bool findpath(const undirected_graph& t, int u, int v,
              std::unordered_map<int, bool>& visited,
              std::vector<int>& path)
{
    visited[u] = true;
    path.push_back(u);
    if (u == v) {
        return true;
    }
    for (auto& neighbour : t.neighbours(u)) {
        if (!visited[neighbour]) {
            if (findpath(t, neighbour, v, visited, path)) {
                return true; 
            }
        }
    }
    path.pop_back();
    return false;
}

std::vector<std::vector<int>>
get_fundamental_cycles_dfs(const undirected_graph& g)
{
    std::vector<std::vector<int>> cycles;
    if (g.all_nodes().empty()) {
        return cycles;
    }

    int source = *g.all_nodes().begin();

    lifo<int> s;
    undirected_graph t = graph_visit(g, source, s);
    undirected_graph c = g - t;

    for (auto& edge : c.all_edges()) {
        int u = edge.from();
        int v = edge.to();

        std::vector<int> path;
        std::unordered_map<int, bool> visited;

        if (findpath(t, u, v, visited, path)) {
            path.push_back(u);  
            cycles.push_back(path);
        }
    }
    return cycles;
}
