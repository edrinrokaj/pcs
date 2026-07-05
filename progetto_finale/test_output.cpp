#include "circuit_solver.hpp"
#include "matrici.hpp"
#include "parser_netlist.hpp"
#include "undirected_graph.hpp"

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>


bool quasi_uguale(double a, double b, double tol = 1e-4) {
    return std::abs(a - b) < tol;
}

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
    
    if (use_de_pina) {
        std::cout << "Test: netlist PDF (De Pina)\n";
    } else {
        std::cout << "Test: netlist PDF (DFS)\n";
    }

    undirected_graph g = build_graph_from_netlist(filename);
    if (g.all_nodes().empty()) {
        std::cerr << "ERRORE: impossibile costruire il grafo da '" << filename << "'\n";
        return EXIT_FAILURE;
    }

    Eigen::MatrixXd B = build_incidence_matrix(g, use_de_pina);
    Eigen::MatrixXd R = build_resistance_matrix(g);
    Eigen::VectorXd v = build_generator_vector(g, use_de_pina);

    CircuitResult res = solve_circuit(B, R, v);
    std::vector<std::string> names = get_resistor_names(g);
    print_output(names, res.resistor_voltages, res.resistor_currents);

    struct valori_attesi {std::string nome; double v_attesi; double i_attesi;};
    std::vector<valori_attesi> attesi = {
        {"R2",  22.0,  2.2},
        {"R3",  -6.0, -0.2},
        {"R4", -28.0, -2.8},
        {"R1",   8.0,  2.0},
        {"R5",  12.0,  3.0},
    };

    bool ok = true;
    for (size_t k = 0; k < names.size(); k++) {
        for (auto& a : attesi) {
            if (names[k] == a.nome) {
                if (!quasi_uguale(res.resistor_voltages(k), a.v_attesi) ||
                    !quasi_uguale(res.resistor_currents(k), a.i_attesi)) {
                    std::cout << "ERRORE (valore inatteso per " << a.nome << ")\n";
                    ok = false;
                }
            }
        }
    }

    if (ok) {
        std::cout << "TEST eseguito con SUCCESSO\n";
        return EXIT_SUCCESS;
    } else {
        return EXIT_FAILURE;
    }
}
