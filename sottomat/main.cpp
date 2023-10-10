#include <iostream>
#include <fstream>

using namespace std;

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main()
{
    int N, M;
    ifstream in("input.txt");
    in >> N >> M;
    int m[N][M];
    int mapp[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            in >> m[i][j];
        }
    }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << m[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int max = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = i+1; k <= N; k++) {
                for (int l = j+1; l <= M; l++) {
                    // dopo aver scelto inizio e fine
                    int sum = 0;
                    for (int ii = i; ii < k; ii++) {
                        for (int jj = j; jj < l; jj++) {
                            sum += m[ii][jj];
                        }
                    }
                    if (sum > max)
                        max = sum;
                }
            }
        }
    }

    ofstream out("output.txt");
    out << max << endl;

    return 0;
}
