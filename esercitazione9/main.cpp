#include "unidirected_graph.hpp"
#include "containers.hpp"
#include "graph_visit.hpp"
#include "recursive_dfs.hpp"
#include "dijkstra.hpp"

int main() {
    unidirected_graph g;
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(1, 6);
    g.add_edge(2, 4);
    g.add_edge(2, 5);
    g.add_edge(2, 7);
    g.add_edge(3, 6);
    g.add_edge(4, 6);
    g.add_edge(4, 7);
    g.add_edge(5, 7);
    g.add_edge(6, 7);
    g.add_edge(6, 8);
    g.add_edge(7, 9);
    g.add_edge(8, 9);

    lifo<int> s;
    auto dfsG = graph_visit(g, 1, s);
    
    fifo<int> q;
    auto bfsG = graph_visit(g, 1, q);

    auto rdfsG = recursive_dfs(g, 1);

    auto dG = dijkstra(g, 1);

    g.save_dot("grafo.dot");
    dfsG.save_dot("dfs.dot");
    bfsG.save_dot("bfs.dot");
    rdfsG.save_dot("rdfs.dot");
    dG.save_dot("dijkstra.dot");

    return 0;
}

