#include "circuit_solver.hpp"
#include "matrici.hpp"
#include "parser_netlist.hpp"
#include "undirected_graph.hpp"

#include <iostream>
#include <string>

int main(int argc, char** argv) {
    std::string filename = "netlist.txt";
    bool use_de_pina = false;

    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (arg == "--depina") {
            use_de_pina = true;
        } else {
            filename = arg;
        }                    
    }

    undirected_graph g = build_graph_from_netlist(filename);
    if (g.all_nodes().empty()) {
        std::cerr << "ERRORE: grafo vuoto o netlist non leggibile.\n";
        return 1;
    }

    Eigen::MatrixXd B = build_incidence_matrix(g,  use_de_pina);
    Eigen::MatrixXd R = build_resistance_matrix(g);
    Eigen::VectorXd v = build_generator_vector(g,  use_de_pina);

    CircuitResult res = solve_circuit(B, R, v);
    std::vector<std::string> names = get_resistor_names(g);

    print_output(names, res.resistor_voltages, res.resistor_currents);
    return 0;
}
