#include <iostream>
#include "unidirected_graph.hpp"

int main() {
    
    unidirected_edge e1(1, 3);
    unidirected_edge e2(3, 1); // invertito
    
    if (e1.from() != 1 || e1.to() != 3) {
        std::cerr << "from/to errato\n";
        return EXIT_FAILURE;
    }
    if (e2.from() != 1 || e2.to() != 3) {
        std::cerr << "non funziona from < to\n";
        return EXIT_FAILURE;
    }

    if (e1 != e2) {
        std::cerr << "operator= non funziona\n";
        return EXIT_FAILURE;
    }
    
    unidirected_edge e3(2, 5);
    
    if (e1 == e3) {
        std::cerr << "operator= non funziona\n";
        return EXIT_FAILURE;
    }

    if (!(e1 < e3)) {
        std::cerr << "oprator< non funziona\n";
        return EXIT_FAILURE;
    }
    
    if (e3 < e1) {
        std::cerr << "operator< non funziona\n";
        return EXIT_FAILURE;
    }

    std::cout << "Stampa arco (1, 3): " << e1 << "\n";

    unidirected_graph g;
    g.add_edge(1, 2);
    g.add_edge(2, 4);
    g.add_edge(3, 2);
    g.add_edge(2, 5);
    g.add_edge(5, 6);
    g.add_edge(5, 7);
    g.add_edge(7, 8);

    std::set<int> nodes = g.all_nodes();
    if (nodes != std::set<int> {1, 2, 3, 4, 5, 6, 7, 8}) {
        std::cerr << "all_nodes non funziona\n";
        return EXIT_FAILURE;
    }

    std::set<unidirected_edge> edges = g.all_edges();
    if (edges.size() != 7) {
        std::cerr << "all_edges non funziona\n";
        return EXIT_FAILURE;
    }

    g.add_edge(7, 8);
    if (g.all_edges().size() != 7) {
        std::cerr << "i duplicati non vengono ignorati\n";
        return EXIT_FAILURE;
    }

    if (g.neighbours(2) != std::set<int>{1, 3, 4, 5}) {
        std::cerr << "neighbours non funziona\n";
        return EXIT_FAILURE;
    }

    if (g.edge_number(unidirected_edge(1, 2)) != 0) {
        std::cerr << "edge_number non funziona\n";
        return EXIT_FAILURE;
    }
    
    if (g.edge_number(unidirected_edge(7, 8)) != 6) {
        std::cerr << "edge_number non funziona\n";
        return EXIT_FAILURE;
    }

    if (g.edge_number(unidirected_edge(4, 7)) != -1) {
        std::cerr << "edge_number non dà errore se gli chiedo di un arco non esistente\n";
        return EXIT_FAILURE;
    }

    if (g.edge_at(0) != unidirected_edge(1, 2)) {
        std::cerr << "edge_at non funziona\n";
        return EXIT_FAILURE;
    }
    
    if (g.edge_at(4) != unidirected_edge(5, 6)) {
        std::cerr << "edge_at non funziona\n";
        return EXIT_FAILURE;
    }

    if (g.edge_at(20) != unidirected_edge(-1, -1)) {
        std::cerr << "edge_at non dà errore se gli dò un numero non esistente\n";
        return EXIT_FAILURE;
    }

    unidirected_graph g2(g);
    if (g2.all_edges() != g.all_edges()) {
        std::cerr << "costruttore di copia non funziona\n";
        return EXIT_FAILURE;
    }
    
    if (g2.all_nodes() != g.all_nodes()) {
        std::cerr << "costruttore di copia non funziona\n";
        return EXIT_FAILURE;
    }

    unidirected_graph g3;
    g3.add_edge(1, 2);
    g3.add_edge(7, 8);

    unidirected_graph diff = g - g3;
    
    if (diff.all_edges() != std::set<unidirected_edge>{unidirected_edge(2, 4), unidirected_edge(2, 3), 
        unidirected_edge(2, 5), unidirected_edge(5, 6), unidirected_edge(5, 7)}) {
        std::cerr << "operator- non funziona\n";    
        return EXIT_FAILURE;
    }

    std::cout << "Nodi: ";
    for (auto& node : g.all_nodes())
        std::cout << node << " ";
    std::cout << "\n";

    std::cout << "Archi numerati:\n";
    for (auto& edge : g.all_edges()) {
        std::cout << "arco " << g.edge_number(edge) << ": " << edge << "\n";
    }
    
    return EXIT_SUCCESS;

}