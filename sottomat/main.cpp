#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    ifstream in("input.txt");
    in >> N >> M;

    int m[N][M];
    int m1[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            in >> m[i][j];
            if (j == 0) {
                m1[i][j] = m[i][j];
            } else {
                m1[i][j] = m1[i][j-1] + m[i][j];
            }
        }
    }

    // per ogni c1 e c2
    int max = 0;
    for (int c1 = 0; c1 < M; c1++) {
        for (int c2 = c1; c2 < M; c2++) {
            int col[N];
            // cout << "C1: " << c1 << " C2: " << c2 << " = ";
            for (int i = 0; i < N; i++) {
                if (c1 == 0) {
                    col[i] = m1[i][c2];
                } else {
                    col[i] = m1[i][c2] - m1[i][c1-1];
                }
            }
            // for (int i = 0; i < N; i++) {
            //     cout << col[i] << " ";
            // }
            // cout << endl;

            int col1[N];
            int lmax = 0;
            for (int i = 0; i < N; i++) {
                int tmp;
                if (i == 0) {
                    tmp = col[i];
                } else {
                    tmp = col1[i-1] + col[i];
                }

                if (tmp < 0) {
                    tmp = 0;
                }

                col1[i] = tmp;
                if (tmp > lmax) {
                    lmax = tmp;
                }
            }
            if (lmax > max) {
                max = lmax;
            }
        }
    }
    // cout << max << endl;

    ofstream out("output.txt");
    out << max << endl;

    return 0;
}

