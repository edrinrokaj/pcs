#include "linear_solver.hpp"

Eigen::VectorXd conjugate_gradient(const Eigen::MatrixXd& A,
                                    const Eigen::VectorXd& b,
                                    const Eigen::VectorXd& x0,
                                    unsigned int it_max,
                                    double res_tol,
                                    unsigned int& steps)
{
    Eigen::VectorXd x = x0;
    Eigen::VectorXd r = b - A * x;
    Eigen::VectorXd p = r;

    const double res_norm_0 = r.norm();
    steps = 0;

    if (res_norm_0 == 0.0) {
        return x;
    }

    while (steps < it_max && r.norm() > res_tol * res_norm_0)
    {
        Eigen::VectorXd Ap = A * p;
        double p_Ap = p.dot(Ap);
        double alpha_k = p.dot(r) / p_Ap;
        x = x + alpha_k * p;
        r = b - A * x;
        double beta_k = p.dot(A * r) / p_Ap;
        p = r - beta_k * p;
        steps++;
    }
    return x;
}

Eigen::VectorXd conjugate_gradient(const Eigen::MatrixXd& A,
                                    const Eigen::VectorXd& b,
                                    double res_tol,
                                    unsigned int it_max)
{
    Eigen::VectorXd x0 = Eigen::VectorXd::Zero(A.rows());
    unsigned int steps = 0;
    return conjugate_gradient(A, b, x0, it_max, res_tol, steps);
}
