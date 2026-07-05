#pragma once

#include <Eigen/Dense>


Eigen::VectorXd conjugate_gradient(const Eigen::MatrixXd& A,
                                    const Eigen::VectorXd& b,
                                    const Eigen::VectorXd& x0,
                                    unsigned int it_max,
                                    double res_tol,
                                    unsigned int& steps);

Eigen::VectorXd conjugate_gradient(const Eigen::MatrixXd& A,
                                    const Eigen::VectorXd& b,
                                    double res_tol = 1.0e-12,
                                    unsigned int it_max = 10000);
