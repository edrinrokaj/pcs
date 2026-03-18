#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, const char *argv[]) {
    
    if (argc!=2) {
        cerr << "Errore nell'inserimento del nome del file\n";
        return 1;
    }
    
    string filename = argv[1];
    ifstream ifs(filename);
    if (!ifs.is_open()) {
        cerr << "Errore nell'apertura del file\n";
        return 1;
    }
    
    while(!ifs.eof()) {
        string città;
        double t1, t2, t3, t4;
        ifs >> città >> t1 >> t2 >> t3 >> t4;
        double media = (t1+t2+t3+t4)/4.0;
        cout << città << " " << media << "\n";
    }

    return 0;
    
}