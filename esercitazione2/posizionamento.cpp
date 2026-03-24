# include <iostream>

int main()
{
    double ad[4] = {0.0, 1.1, 2.2, 3.3};
    float af[8] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    int ai[3] = {0, 1, 2};

    int x = 1;
    float y = 1.1;

    (&y)[1] = 0;

    std::cout << x << "\n";
    std::cout << "Indirizzo double ad[4]: " << &ad[0] << "\n";
    std::cout << "Indirizzo float af[8]: " << &af[0] << "\n";
    std::cout << "Indirizzo int ai[3]: " << &ai[0] << "\n";
    std::cout << "Indirizzo int x: " << &x << "\n";
    std::cout << "Indirizzo float y: " << &y << "\n";
    std::cout << "Dimensione double ad[4]: " << sizeof(ad) << "\n";
    std::cout << "Dimensione float af[8]: " << sizeof(af) << "\n";
    std::cout << "Dimensione int ai[3]: " << sizeof(ai) << "\n";
    std::cout << "Dimensione int x: " << sizeof(x) << "\n";
    std::cout << "Dimensione float y: " << sizeof(y) << "\n";

return 0;
}
