#pragma once

#include "undirected_graph.hpp"

#include <string>

undirected_graph build_graph_from_netlist(const std::string& filename);
