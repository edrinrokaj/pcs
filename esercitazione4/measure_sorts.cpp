#include <iostream>
#include <vector>
#include <algorithm>
#include "algoritmi_ordinamento.hpp"
#include "randfiller.h"
#include "timecounter.h"

int main(void) {
    randfiller rf;
    timecounter tc;
    
    for (int n = 2; n <= 8192; n *= 2) {
        std::cout << "Dimensione vettore: " << n << "\n";
        
        std::vector<int> v;
        v.resize(n);
        rf.fill(v, -10000, 10000);
        
        std::vector<int> v_bubble = v;
        std::vector<int> v_insertion = v;
        std::vector<int> v_selection = v;
        std::vector<int> v_std = v;

        std::cout << "Tempo di esecuzione algoritmi:\n";

        std::cout << "Bubblesort:\n";
        tc.tic();
        bubble_sort(v_bubble);
        double secs_bubble = tc.toc();
        std::cout << secs_bubble << " secondi;\n";

        std::cout << "Insertionsort:\n";
        tc.tic();
        insertion_sort(v_insertion);
        double secs_insertion = tc.toc();
        std::cout << secs_insertion << " secondi;\n";

        std::cout << "Selectionsort:\n";
        tc.tic();
        selection_sort(v_selection);
        double secs_selection = tc.toc();
        std::cout << secs_selection << " secondi;\n";

        std::cout << "Standardsort:\n";
        tc.tic();
        std::sort(v_std.begin(), v_std.end());
        double secs_std = tc.toc();
        std::cout << secs_std << " secondi;\n";

        std::cout << "---------------------------------------------------------------------------\n";
    }

    return 0;
}