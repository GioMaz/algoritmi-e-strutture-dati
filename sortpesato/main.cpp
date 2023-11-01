#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream in("input.txt");

    int N;
    in >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        in >> v[i];
    }

    // 6
    // 6 2 5 1 3 4
    int turni = 0;
    int prezzo = 0;
    bool trovato;
    do {
        // find 1 (min unordered)
        int lowest = N+1;
        int ilowest;
        trovato = false;
        for (int j = 0; j < N; j++) {
            if (v[j] < lowest && v[j] != j+1) {
                lowest = v[j];
                ilowest = j;
                trovato = true;
            }
        }

        if (trovato) {
            // find 4 (unordered swap)
            // if trovato then 4 is not in place
            int inext;
            for (int j = 0; j < N; j++) {
                if (v[j] == ilowest+1) {
                    inext = j;
                }
            }

            // cout << "INEXT: " << inext << endl;
            if (lowest > 2 && inext != v[ilowest]-1) {
                cout << "swap: " << v[0] << " " << v[ilowest] << endl;
                swap(v[0], v[ilowest]);
                prezzo += v[inext] + v[ilowest];
            } else {
                cout << "swap: " << v[ilowest] << " " << v[inext] << endl;
                swap(v[ilowest], v[inext]);
                turni++;
                prezzo += v[inext] + v[ilowest];
            }

            // swap 1 and 4

        }
    } while (trovato);

    ofstream out("output.txt");
    // << turni << " " << prezzo << endl;
    out << turni << " " << prezzo << endl;

    return 0;
}
