#include <iostream>
#include <Eigen/Dense>
#include "conjugate_gradient.hpp"

int main(void) {
    
    for (int n = 2; n <= 100; n+=2) {
        Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n);
        Eigen::MatrixXd A = B.transpose() * B;
        Eigen::VectorXd x_ex = Eigen::VectorXd::Ones(n);
        Eigen::VectorXd b = A * x_ex;
        Eigen::VectorXd x0 = Eigen::VectorXd::Zero(n);

        double tol = 1.0e-12;
        unsigned int it_max = 10000;

        ResultCG result = conjugate_gradient(A, b, x0, tol, it_max);
        double err_rel = (result.x - x_ex).norm() / x_ex.norm();

        if (!result.converged) {
            std::cerr << "Il metodo non converge per la dimensione n = " << n << "\n";
            return EXIT_FAILURE;
        }

        if (err_rel > 1e-10) {
            std::cerr << "Errore relativo di " << err_rel << " per la dimensione " << n << "\n";
            return EXIT_FAILURE;
        }
        std::cout << "Dimensione matrice: " << n << "\n";
        std::cout.precision(4);
        std::cout<< std::scientific<< "it"<< "/"<< "it_max"<< std::endl;
        std::cout<< std::scientific<< result.it << "/"<< it_max<< std::endl;
        std::cout<< std::scientific<< "err_rel"<< std::endl;
        std::cout<< std::scientific<< err_rel<< std::endl;
        std::cout<< std::scientific<< "soluzione"<< std::endl;
        std::cout<< std::scientific<< result.x << std::endl;
    }

    return EXIT_SUCCESS;
}