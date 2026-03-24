#include <iostream>

int main() {
    static const int N = 10;
    double arr[N] = {0.2, 5.7, 9.8, 34.6, 7.9, 15.4, 0.7, 12.5, 21.3, 16.8};
    
    bool scambi;
    do {
        scambi = false; 
        for (int i=0; i<N-1; i++) {
            double presente = arr[i];
            if (presente>arr[i+1]) {
                arr[i] = arr[i+1];
                arr[i+1] = presente;
                scambi = true;
            }        
        } 
    } while (scambi);

    std::cout << "Array ordinato: ";
    for (int i=0; i<N; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    return 0;

}