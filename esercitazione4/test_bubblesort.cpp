#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include "algoritmi_ordinamento.hpp"
#include "is_sorted.hpp"
#include "randfiller.h"

int main(void) {
    std::cout << "Test unitario per l'algoritmo Bubblesort:\n";
    
    randfiller rf;
    for (int i = 0; i < 100; i++) {
        int d = rand()%500;
        std::vector<int> vi;
        vi.resize(d);
        rf.fill(vi, -10000, 10000);
        bubble_sort(vi);
        if (!is_sorted(vi)) {
            std::cerr << "Errore nell'ordinamento al test del vettore numero " << (i+1) 
            << " di dimensione " << d << "\n";
            return EXIT_FAILURE;
        }
    }

    std::vector<std::string> stringhe = {"Italia", "Francia", "Belgio", 
        "Germania", "Paesi Bassi", "Regno Unito", "Spagna", "Svizzera", "Austria", 
        "Lussemburgo", "Danimarca", "Norvegia", "Svezia", "Finlandia"};
    bubble_sort(stringhe);
    if (!is_sorted(stringhe)) {
            std::cerr << "Errore nell'ordinamento delle stringhe\n";
            return EXIT_FAILURE;
    }

    std::cout << "Tutti i test di ordinamento Bubblesort sono anadati a buon fine\n";
    return EXIT_SUCCESS;
}