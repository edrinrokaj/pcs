#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include "algoritmi_ordinamento.hpp"
#include "is_sorted.hpp"
#include "randfiller.h"

int main(void) {
    
    randfiller rf;
    for (int i = 0; i < 100; i++) {
        int d = rand()%500;
        std::vector<int> vi;
        vi.resize(d);
        rf.fill(vi, -10000, 10000);
        merge_sort(vi, 0, vi.size()-1);
        if (!is_sorted(vi)) {
            return EXIT_FAILURE;
        }
    }

    std::vector<std::string> stringhe = {"Italia", "Francia", "Belgio", 
        "Germania", "Paesi Bassi", "Regno Unito", "Spagna", "Svizzera", "Austria", 
        "Lussemburgo", "Danimarca", "Norvegia", "Svezia", "Finlandia"};
    merge_sort(stringhe, 0, stringhe.size()-1);
    if (!is_sorted(stringhe)) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}