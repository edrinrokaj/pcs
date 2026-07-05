#include "depina_min_cycles.hpp"

#include "containers.hpp"
#include "dijkstra_path.hpp"
#include "graph_visit.hpp"

#include <limits>

int dot_product_mod2(const std::vector<int>& a, const std::vector<int>& b) {
    int sum = 0;
    int n = a.size();
    for (int i = 0; i < n; i++) {
        sum += (a[i] * b[i]); 
    }
    return sum % 2;
}

void xor_in_place(std::vector<int>& a, const std::vector<int>& b) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        a[i] = (a[i] + b[i]) % 2;
    }
}

undirected_graph graph_lifting(const undirected_graph& g,
                                const std::vector<int>& s,
                                int offset)
{
    undirected_graph g_prime;
    for (auto& edge : g.all_edges()) {
        int edge_index = g.edge_number(edge);
        int u = edge.from();
        int v = edge.to();
        if (s[edge_index] == 1) {
            g_prime.add_edge(u, v + offset);
            g_prime.add_edge(u + offset, v);
        } else {
            g_prime.add_edge(u, v);
            g_prime.add_edge(u + offset, v + offset);
        }
    }
    return g_prime;
}

std::vector<int>
find_minimal_path(const undirected_graph& g,
                   const std::vector<int>& s_i, int offset)
{
    undirected_graph g_prime = graph_lifting(g, s_i, offset);
    int min_length = std::numeric_limits<int>::max();
    std::vector<int> minimal_path_nodes;

    for (auto& v : g.all_nodes()) {
        std::vector<int> path = dijkstra_path(g_prime, v, v + offset);
        int l = path.size();
        if (!path.empty() && l < min_length) {
            min_length = l;
            minimal_path_nodes = path;
        }
    }
    return minimal_path_nodes;
}

std::vector<int> unshift_path(const std::vector<int>& shifted_path, int offset) {
    std::vector<int> path;
    path.reserve(shifted_path.size());
    for (int node : shifted_path) {
        if (node >= offset) {
            path.push_back(node - offset);
        } else {
            path.push_back(node);
        }
    }
    return path;
}

std::vector<int>
path_to_incidence(const undirected_graph& g,
                  const std::vector<int>& shifted_path,
                  int offset, int m)
{
    std::vector<int> c(m, 0);
    int p = shifted_path.size();
    for (int i = 0; i < p - 1; i++) {
        int u = shifted_path[i];
        int v = shifted_path[i + 1];
        if (u >= offset) {
            u -= offset;
        }
        if (v >= offset) {
            v -= offset;
        }
        undirected_edge e(u, v);
        int e_n = g.edge_number(e);
        if (e_n != -1) {
            c[e_n] = (c[e_n] + 1) % 2;
        }
    }
    return c;
}

std::vector<std::vector<int>>
get_fundamental_cycles_dePina(const undirected_graph& g)
{
    std::vector<std::vector<int>> cycles;
    if (g.all_nodes().empty()) {
        return cycles;
    }

    int source = *g.all_nodes().begin();
    int offset = *g.all_nodes().rbegin() + 1;

    lifo<int> s;
    undirected_graph t = graph_visit(g, source, s);
    undirected_graph c = g - t;

    int m = g.all_edges().size();
    int k = c.all_edges().size();

    std::vector<std::vector<int>> base(k, std::vector<int>(m, 0));
    int i = 0;
    for (auto& edge : c.all_edges()) {
        int edge_index = g.edge_number(edge);
        base[i][edge_index] = 1;
        i++;
    }

    for (int idx = 0; idx < k; idx++) {
        std::vector<int> shifted_path = find_minimal_path(g, base[idx], offset);
        std::vector<int> incidence = path_to_incidence(g, shifted_path, offset, m);
        cycles.push_back(unshift_path(shifted_path, offset));

        for (int j = idx + 1; j < k; j++) {
            if (dot_product_mod2(incidence, base[j]) == 1) {
                xor_in_place(base[j], base[idx]);
            }
        }
    }
    return cycles;
}
