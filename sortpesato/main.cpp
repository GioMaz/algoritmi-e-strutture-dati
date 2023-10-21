#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream in("input.txt");

    int N;
    in >> N;
    // vector<int> v1(N);
    vector<int> v2(N);
    for (int i = 0; i < N; i++) {
        int tmp;
        in >> tmp;
        // v1[i] = v2[i] = tmp;
        v2[i] = tmp;
    }

    // int N = 100000;
    // vector<int> v2(N);
    // for (int i = 0; i < N; i++) {
    //     v2[i] = i+1;
    // }
    // int tmp;

    // tmp = v2[500];
    // v2[500] = v2[501];
    // v2[501] = tmp;

    // tmp = v2[501];
    // v2[501] = v2[600];
    // v2[600] = tmp;

    // TURNI
    // int turni = 0;
    // for (int i = 1; i <= N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         if (v1[j] == i && (i-1) != j) {
    //             // cout << "SCAMBIO " << v[j] << " E " << v[i-1] << endl;
    //             int tmp = v1[i-1];
    //             v1[i-1] = v1[j];
    //             v1[j] = tmp;
    //             turni++;
    //         }
    //     }
    // }
    // cout << turni << endl;

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
            if (v2[j] < lowest && v2[j] != j+1) {
                lowest = v2[j];
                ilowest = j;
                trovato = true;
            }
        }

        if (trovato) {
            // find 4 (unordered swap)
            // if trovato then 4 is not in place
            int inext;
            for (int j = 0; j < N; j++) {
                if (v2[j] == ilowest+1) {
                    inext = j;
                }
            }

            // swap 1 and 4
            int tmp = v2[ilowest];
            // cout << "swap: " << v2[ilowest] << " " << v2[inext] << endl;
            v2[ilowest] = v2[inext];
            v2[inext] = tmp;

            turni++;
            prezzo += tmp + v2[ilowest];
        }
    } while (trovato);

    ofstream out("output.txt");
    // cout << turni << " " << prezzo << endl;
    out << turni << " " << prezzo << endl;

    return 0;
}
