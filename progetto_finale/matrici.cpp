#include "matrici.hpp"

#include "depina_min_cycles.hpp"
#include "metodo_dfs.hpp"

#include <algorithm>

bool sort_by_component_number(const ComponentEdge& a, const ComponentEdge& b) {
    int num_a = std::stoi(a.comp().name.substr(1));
    int num_b = std::stoi(b.comp().name.substr(1));
    return num_a < num_b;
}

bool is_in_cycle_forward(int from, int to, const std::vector<int>& cycle) {
    for (size_t i = 0; i + 1 < cycle.size(); i++) {
        if (cycle[i] == from && cycle[i + 1] == to) {
            return true;
        }
    }
    return false;
}

bool is_in_cycle_backward(int from, int to, const std::vector<int>& cycle) {
    for (size_t i = 0; i + 1 < cycle.size(); i++) {
        if (cycle[i + 1] == from && cycle[i] == to) {
            return true;
        }
    }
    return false;
}

std::vector<std::vector<int>>
get_fundamental_cycles(const undirected_graph& g, bool use_de_pina) {
    if (use_de_pina) {
        return get_fundamental_cycles_dePina(g);
    } else {
        return get_fundamental_cycles_dfs(g);
    }
}


Eigen::MatrixXd
build_incidence_matrix(const undirected_graph& g, bool use_de_pina)
{
    std::vector<ComponentEdge> res_edges = g.all_component_edges('R');
    std::sort(res_edges.begin(), res_edges.end(), sort_by_component_number);

    std::vector<std::vector<int>> cycles = get_fundamental_cycles(g, use_de_pina);

    int m = res_edges.size();
    int n = cycles.size();

    Eigen::MatrixXd B = Eigen::MatrixXd::Zero(m, n);
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            int u = res_edges[i].from();
            int v = res_edges[i].to();
            if (is_in_cycle_forward(u, v, cycles[j])) {
                B(i, j) = +1;
            } else if (is_in_cycle_backward(u, v, cycles[j])) {
                B(i, j) = -1;
            }
        }
    }
    return B;
}

Eigen::MatrixXd build_resistance_matrix(const undirected_graph& g) {
    std::vector<ComponentEdge> res_edges = g.all_component_edges('R');
    std::sort(res_edges.begin(), res_edges.end(), sort_by_component_number);

    int m = res_edges.size();
    Eigen::VectorXd r_vec(m);
    for (int i = 0; i < m; i++) {
        r_vec(i) = res_edges[i].comp().value;
    }
    return r_vec.asDiagonal();
}

Eigen::VectorXd
build_generator_vector(const undirected_graph& g, bool use_de_pina)
{
    std::vector<ComponentEdge> gen_edges = g.all_component_edges('V');
    std::sort(gen_edges.begin(), gen_edges.end(), sort_by_component_number);

    std::vector<std::vector<int>> cycles = get_fundamental_cycles(g, use_de_pina);
    int n = cycles.size();

    Eigen::VectorXd v = Eigen::VectorXd::Zero(n);
    for (int j = 0; j < n; j++) {
        for (auto& ge : gen_edges) {
            int pos = ge.comp().positive_node;
            int neg = ge.comp().negative_node;
            double val = ge.comp().value;

            if (is_in_cycle_forward(pos, neg, cycles[j])) {
                v(j) -= val;
            } else if (is_in_cycle_forward(neg, pos, cycles[j])) {
                v(j) += val;
            } 
        }
    }
    return v;
}

std::vector<std::string> get_resistor_names(const undirected_graph& g) {
    std::vector<ComponentEdge> res_edges = g.all_component_edges('R');
    std::sort(res_edges.begin(), res_edges.end(), sort_by_component_number);

    std::vector<std::string> names;
    names.reserve(res_edges.size());
    for (auto& re : res_edges) {
        names.push_back(re.comp().name);
    }
    return names;
}
