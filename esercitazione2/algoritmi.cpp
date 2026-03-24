#include <iostream>
#include <algorithm>
#include <cmath>

int main() {
    static const int N = 10;
    double arr[N] = {0.2, 5.7, 9.8, 34.6, 7.9, 15.4, 0.7, 12.5, 21.3, 16.8};
    double min = arr[0];
    double max = arr[0];
    double sum = 0.0;

    for (int i=0; i<N; i++) {
        min = std::min(min, arr[i]);
        max = std::max(max, arr[i]);
        sum += arr[i];
    }
    
    double media = sum/N;

    double somma_scarti_quadrati = 0.0;
    for (int i=0; i<N; i++) {
        double scarto = arr[i] - media;
        somma_scarti_quadrati += (scarto*scarto);
    }
    double varianza = somma_scarti_quadrati/N;
    double deviazione_standard = std::sqrt(varianza);

    std::cout << "Minimo: " << min << "\n";
    std::cout << "Massimo: " << max << "\n";
    std::cout << "Media: " << media << "\n";
    std::cout << "Deviazione standard: " << deviazione_standard << "\n";

    return 0;

}