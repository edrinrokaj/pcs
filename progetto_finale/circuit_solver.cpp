#include "circuit_solver.hpp"

#include "linear_solver.hpp"

#include <cmath>
#include <iostream>

CircuitResult solve_circuit(const Eigen::MatrixXd& B,
                             const Eigen::MatrixXd& R,
                             const Eigen::VectorXd& v)
{
    Eigen::MatrixXd A = B.transpose() * R * B;
    Eigen::VectorXd i = conjugate_gradient(A, v);
    Eigen::VectorXd i_R = B * i;
    Eigen::VectorXd v_R = R * i_R;
    return { i, i_R, v_R };
}

double clean_zero(double x, double tol) {
    if (std::abs(x) < tol) {
        return 0.0;
    } else {
        return x;
    }
}

void print_output(const std::vector<std::string>& resistor_names,
                  const Eigen::VectorXd& resistor_voltages,
                  const Eigen::VectorXd& resistor_currents)
{
    const int m = resistor_names.size();
    for (int k = 0; k < m; ++k) {
        std::cout << resistor_names[k]
                  << ": V = " << clean_zero(resistor_voltages(k)) << " volts, "
                  << "I = " << clean_zero(resistor_currents(k)) << " amps.\n";
    }
}
