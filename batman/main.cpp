#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

struct nodo {
    vector<int> vic;
    bool visitato = false;
};

void dfs_aux(vector<nodo> &g,
        vector<int> &ab, // num di percorsi da ogni nodo
        vector<bool> &cd, // nodi chiusi
        int cur,
        int b)
{
    g[cur].visitato = true;
    if (cur == b) {
        ab[cur] = 1;
        cd[cur] = true;
        return;
    }

    for (int vic : g[cur].vic) {
        if (!g[vic].visitato) {
            dfs_aux(g, ab, cd, vic, b);
        }
        if (cd[vic]) {
            ab[cur] += ab[vic];
        }
    }
    cd[cur] = true;
}

int dfs(vector<nodo> &g, int a, int b)
{
    vector<int> ab(g.size(), 0);
    vector<bool> cd(g.size(), false);
    dfs_aux(g, ab, cd, a, b);

    for (int i = 0; i < ab.size(); i++)
        cout << "[" << i << "]: " << ab[i] << endl;

    return ab[a];
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int N, M, S, D;
    in >> N >> M;
    // if (N == 0) {
    //     out << 0;
    //     return 0;
    // }
    in >> S >> D;
    // if (M == 0) {
    //     out << (S == D);
    //     return 0;
    // }

    vector<nodo> g(N);
    for (int i = 0; i < M; i++) {
        int tmp1, tmp2;
        in >> tmp1 >> tmp2;
        g[tmp1].vic.push_back(tmp2);
    }

    // for (int i = 0; i < N; i++) {
    //     cout << i << ": ";
    //     for (int j = 0; j < g[i].vic.size(); j++) {
    //         cout << g[i].vic[j] << " ";
    //     }
    //     cout << endl;
    // }

    int res = dfs(g, S, D);
    out << res << endl;

    return 0;
}
