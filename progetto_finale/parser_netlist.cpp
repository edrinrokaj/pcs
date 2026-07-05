#include "parser_netlist.hpp"

#include "components.hpp"

#include <fstream>
#include <iostream>

undirected_graph build_graph_from_netlist(const std::string& filename) {
    undirected_graph g;
    std::ifstream ifs(filename);
    if (!ifs.is_open()) {
        std::cerr << "ERRORE: impossibile aprire la netlist '" << filename << "'\n";
        return g;
    }

    std::string name;
    double value;
    int node_a, node_b;

    while (!ifs.eof()) {
        if (ifs >> name >> value >> node_a >> node_b) {
            char type = name[0];
            if (type == 'R' || type == 'r') {
                Component c{name, value, 'R', -1, -1};
                g.add_component(node_a, node_b, c);
            } else if (type == 'V' || type == 'v') {
                Component c{name, value, 'V', node_a, node_b};
                g.add_component(node_a, node_b, c);
            } else {
                std::cerr << "ERRORE: componente " << name << " non valido.\n";
            }
        }
    }
    return g;
}
