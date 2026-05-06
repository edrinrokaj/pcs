#include <iostream>
#include <vector>
#include <algorithm>
#include "algoritmi_ordinamento.hpp"
#include "randfiller.h"
#include "timecounter.h"

int main(void) {
    randfiller rf;
    timecounter tc;

// trovo la soglia dalla quale il quick diventa più veloce dell'insertion
    
    for (int n = 4; n <= 400; n += 4) {
        std::cout << "Dimensione vettore: " << n << "\n";
        double sum_secs_bubble = 0.0;
        double sum_secs_insertion = 0.0;
        double sum_secs_selection = 0.0;
        double sum_secs_merge = 0.0;
        double sum_secs_quick = 0.0;
        double sum_secs_std = 0.0;
        for (int i = 0; i < 100; i++) {
            std::vector<int> v;
            v.resize(n);
            rf.fill(v, -10000, 10000);
        
            std::vector<int> v_bubble = v;
            std::vector<int> v_insertion = v;
            std::vector<int> v_selection = v;
            std::vector<int> v_merge = v;
            std::vector<int> v_quick = v;
            std::vector<int> v_std = v;

            tc.tic();
            bubble_sort(v_bubble);
            sum_secs_bubble += tc.toc();

            tc.tic();
            insertion_sort(v_insertion);
            sum_secs_insertion += tc.toc();

            tc.tic();
            selection_sort(v_selection);
            sum_secs_selection += tc.toc();

            tc.tic();
            merge_sort(v_merge, 0, v_merge.size()-1);
            sum_secs_merge += tc.toc();

            tc.tic();
            quick_sort(v_quick, 0, v_quick.size()-1);
            sum_secs_quick += tc.toc();

            tc.tic();
            std::sort(v_std.begin(), v_std.end());
            sum_secs_std += tc.toc();

        }

        std::cout << "Tempo medio di esecuzione algoritmi:\n";

        std::cout << "Bubblesort:\n";
        std::cout << (sum_secs_bubble/100) << " secondi;\n";
        
        std::cout << "Insertionsort:\n";
        std::cout << (sum_secs_insertion/100) << " secondi;\n";
        
        std::cout << "Selectionsort:\n";
        std::cout << (sum_secs_selection/100) << " secondi;\n";
      
        std::cout << "Mergesort:\n";
        std::cout << (sum_secs_merge/100) << " secondi;\n";

        std::cout << "Quicksort:\n";
        std::cout << (sum_secs_quick/100) << " secondi;\n";
        
        std::cout << "Standardsort:\n";
        std::cout << (sum_secs_std/100) << " secondi;\n";
        
        std::cout << "---------------------------------------------------------------------------\n";
    }

// ora studio il comportamento di tutti gli algoritmi anche per vettori grandi

    for (int n = 2; n <= 8192; n *= 2) {
        std::cout << "Dimensione vettore: " << n << "\n";
        double sum_secs_bubble = 0.0;
        double sum_secs_insertion = 0.0;
        double sum_secs_selection = 0.0;
        double sum_secs_merge = 0.0;
        double sum_secs_quick = 0.0;
        double sum_secs_modifiedquick = 0.0;
        double sum_secs_std = 0.0;
        for (int i = 0; i < 100; i++) {
            std::vector<int> v;
            v.resize(n);
            rf.fill(v, -10000, 10000);
        
            std::vector<int> v_bubble = v;
            std::vector<int> v_insertion = v;
            std::vector<int> v_selection = v;
            std::vector<int> v_merge = v;
            std::vector<int> v_quick = v;
            std::vector<int> v_modifiedquick = v;
            std::vector<int> v_std = v;

            tc.tic();
            bubble_sort(v_bubble);
            sum_secs_bubble += tc.toc();

            tc.tic();
            insertion_sort(v_insertion);
            sum_secs_insertion += tc.toc();

            tc.tic();
            selection_sort(v_selection);
            sum_secs_selection += tc.toc();

            tc.tic();
            merge_sort(v_merge, 0, v_merge.size()-1);
            sum_secs_merge += tc.toc();

            tc.tic();
            quick_sort(v_quick, 0, v_quick.size()-1);
            sum_secs_quick += tc.toc();

            tc.tic();
            modified_quick_sort(v_modifiedquick, 0, v_modifiedquick.size()-1);
            sum_secs_modifiedquick += tc.toc();

            tc.tic();
            std::sort(v_std.begin(), v_std.end());
            sum_secs_std += tc.toc();

        }

        std::cout << "Tempo medio di esecuzione algoritmi:\n";

        std::cout << "Bubblesort:\n";
        std::cout << (sum_secs_bubble/100) << " secondi;\n";
        
        std::cout << "Insertionsort:\n";
        std::cout << (sum_secs_insertion/100) << " secondi;\n";
        
        std::cout << "Selectionsort:\n";
        std::cout << (sum_secs_selection/100) << " secondi;\n";
      
        std::cout << "Mergesort:\n";
        std::cout << (sum_secs_merge/100) << " secondi;\n";

        std::cout << "Quicksort:\n";
        std::cout << (sum_secs_quick/100) << " secondi;\n";

        std::cout << "Modifiedquicksort:\n";
        std::cout << (sum_secs_modifiedquick/100) << " secondi;\n";
        
        std::cout << "Standardsort:\n";
        std::cout << (sum_secs_std/100) << " secondi;\n";
        
        std::cout << "---------------------------------------------------------------------------\n";
    }


    return 0;
}