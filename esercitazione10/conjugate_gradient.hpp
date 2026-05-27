#pragma once

#include <Eigen/Dense>

struct ResultCG {
    Eigen::VectorXd x;
    unsigned int it;
    double res_norm;
    bool converged;
};

ResultCG conjugate_gradient(
    const Eigen::MatrixXd& A, 
    const Eigen::VectorXd& b, 
    const Eigen::VectorXd& x0, 
    double tol,
    const unsigned int it_max) 
{
    Eigen::VectorXd x = x0;
    Eigen::VectorXd r = b - A * x;
    Eigen::VectorXd p = r;
    
    unsigned int it = 0;

    while (it < it_max && r.norm() > tol) {
        double pAp = p.dot(A * p);
        double alpha = p.dot(r) / pAp;
        x += alpha * p;
        r = b - A * x;
        double beta = p.dot(A * r) / pAp;
        p = r - beta * p;
        it++;
    }
    ResultCG result = {x, it, r.norm(), r.norm() <= tol};
    return result;
}







   



