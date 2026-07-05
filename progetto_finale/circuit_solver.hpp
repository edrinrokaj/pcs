#pragma once

#include <Eigen/Dense>
#include <string>
#include <vector>

struct CircuitResult {
    Eigen::VectorXd mesh_currents;
    Eigen::VectorXd resistor_currents;
    Eigen::VectorXd resistor_voltages;
};

CircuitResult solve_circuit(const Eigen::MatrixXd& B,
                             const Eigen::MatrixXd& R,
                             const Eigen::VectorXd& v);

double clean_zero(double x, double tol = 1.0e-9);

void print_output(const std::vector<std::string>& resistor_names,
                  const Eigen::VectorXd& resistor_voltages,
                  const Eigen::VectorXd& resistor_currents);
