#include <iostream>
#include "rational.hpp"

int main(void)
{
    rational<int> pìù_inf(1,0);
    rational<int> meno_inf(-1,0);
    rational<int> nan(0,0);
    rational<int> zero(0,1);

    std::cout << "-3/-6 = " << rational<int>(-3,-6) << "\n";
    std::cout << "5/0 = " << rational<int>(5,0)  << "\n";
    std::cout << "-16/0 = " << rational<int>(-16,0) << "\n";  

    std::cout << "1/2 + 1/3 = "<< rational<int>(1,2) + rational<int>(1,3)  << "\n";
    std::cout << "1/2 + inf = " << rational<int>(1,2) + pìù_inf << "\n";
    std::cout << "1/2 + (-inf) = " << rational<int>(1,2) + meno_inf << "\n";
    std::cout << "inf + inf = " << pìù_inf + pìù_inf << "\n";
    std::cout << "inf + (-inf) = " << pìù_inf + meno_inf << "\n";
    std::cout << "1/2 + nan = " << rational<int>(1,2) + nan << "\n";
    std::cout << "+inf + nan = " << pìù_inf + nan << "\n";

    std::cout << "1/2 - 1/3 = "<< rational<int>(1,2) - rational<int>(1,3)  << "\n";
    std::cout << "1/2 - inf = " << rational<int>(1,2) - pìù_inf << "\n";
    std::cout << "1/2 - (-inf) = " << rational<int>(1,2) - meno_inf << "\n";
    std::cout << "inf - inf = " << pìù_inf - pìù_inf << "\n";
    std::cout << "inf - (-inf) = " << pìù_inf - meno_inf << "\n";
    std::cout << "1/2 - nan = " << rational<int>(1,2) - nan << "\n";
    std::cout << "inf - nan = " << pìù_inf - nan << "\n";

    std::cout << "2/3 * 3/4 = " << rational<int>(2,3) * rational<int>(3,4)  << "\n";
    std::cout << "2/3 * 3/-4 = " << rational<int>(2,3)* rational<int>(3,-4)  << "\n";
    std::cout << "1/2 * 0 = " << rational<int>(1,2) * zero << "\n";
    std::cout << "1/2 * inf = " << rational<int>(1,2) * pìù_inf << "\n";
    std::cout << "-1/2 * inf = " << rational<int>(-1,2) * pìù_inf << "\n";
    std::cout << "inf * inf = " << pìù_inf * pìù_inf << "\n";
    std::cout << "-inf * inf = " << meno_inf * pìù_inf << "\n";
    std::cout << "-inf * -inf = " << meno_inf * meno_inf << "\n";
    std::cout << "0 * inf = " << zero * pìù_inf << "\n";
    std::cout << "1/2 * nan = " << rational<int>(1,2) * nan << "\n";
    std::cout << "inf * nan = " << pìù_inf * nan << "\n";

    std::cout << "2/3 / 3/4 = " << rational<int>(2,3) / rational<int>(3,4)  << "\n";
    std::cout << "-2/3 / 3/4 = " << rational<int>(-2,3) / rational<int>(3,4)  << "\n";
    std::cout << "1/2 / 0 = " << rational<int>(1,2) / zero << "\n";
    std::cout << "-1/2 / 0 = " << rational<int>(-1,2) / zero << "\n";
    std::cout << "0 / 0 = " << zero / zero << "\n";
    std::cout << "1/2 / inf = " << rational<int>(1,2) / pìù_inf << "\n";
    std::cout << "-1/2 / inf = " << rational<int>(-1,2) / pìù_inf << "\n";
    std::cout << "-1/2 / -inf = " << rational<int>(-1,2) / meno_inf << "\n";
    std::cout << "inf / inf = " << pìù_inf / pìù_inf << "\n";
    std::cout << "-inf / inf = " << meno_inf / pìù_inf << "\n";
    std::cout << "-inf / -inf = " << meno_inf / meno_inf << "\n";
    std::cout << "+inf / 2 = " << pìù_inf / rational<int>(2,1)  << "\n";
    std::cout << "+inf / -2 = " << pìù_inf / rational<int>(-2,1)  << "\n";
    std::cout << "0 / inf = " << zero / pìù_inf << "\n";
    std::cout << "1/2 / nan = " << rational<int>(1,2) / nan << "\n";
    std::cout << "inf / nan = " << pìù_inf / nan << "\n";

    return 0;
}