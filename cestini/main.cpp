#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

static vector<vector<int>> c;

void inizia(int N, int M)
{
    c = vector<vector<int>>(M);
    for (int i = 0; i < N; i++) {
        c[0].push_back(i);
    }

    // for (int i = 0; i < M; i++) {
    //     cout << i << ": ";
    //     for (int j = 0; j < c[i].size(); j++) {
    //         cout << c[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}

void sposta(int a, int b)
{
    c[b].push_back(c[a].back());
    c[a].pop_back();
}

int controlla(int a, int i)
{
    if (i >= c[a].size()) {
        return -1;
    } else {
        return c[a][i];
    }
}

// int main() {
//     ifstream in("input.txt");
//     int N, M, Q;
//     in >> N >> M >> Q;
// 
//     inizia(N, M);
// 
//     ofstream out("output.txt");
//     for (int i = 0; i < Q; i++) {
//         char t;
//         int a, b;
//         in >> t >> a >> b;
//         if (t == 's') {
//             sposta(a, b);
//         } else {
//             cout << controlla(a, b) << '\n';
//         }
//     }
// 
//     return 0;
// }
