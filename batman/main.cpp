#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

struct nodo {
    vector<int> vic;
    bool visitato = false;
};

vector<nodo> transpose(vector<nodo> &g)
{
    vector<nodo> gt(g.size());
    for (int i = 0; i < g.size(); i++) {
        for (int vic : g[i].vic) {
            gt[vic].vic.push_back(i);
        }
    }
    return gt;
}

void tsdfs(vector<nodo> &g, vector<int> &s, int cur)
{
    g[cur].visitato = true;
    for (int vic : g[cur].vic) {
        if (!g[vic].visitato) {
            tsdfs(g, s, vic);
        }
    }
    s.push_back(cur);
}

vector<int> ts(vector<nodo> &g)
{
    vector<int> s;
    for (int i = 0; i < g.size(); i++) {
        if (!g[i].visitato) {
            tsdfs(g, s, i);
        }
    }
    return s;
}

void ccdfs(vector<nodo> &g, vector<int> &id, int c, int cur)
{
    id[cur] = c;
    for (int vic : g[cur].vic) {
        if (id[vic] == 0) {
            ccdfs(g, id, c, vic);
        }
    }
}

vector<int> cc(vector<nodo> &g, vector<int> s)
{
    vector<int> id(g.size(), 0);
    int c = 0;
    while (!s.empty()) {
        int cur = s.back();
        s.pop_back();
        if (id[cur] == 0) {
            c++;
            ccdfs(g, id, c, cur);
        }
    }
    return id;
}

vector<int> scc(vector<nodo> g)
{
    vector<int> s = ts(g);
    vector<nodo> gt = transpose(g);
    return cc(gt, s);
}

vector<int> cattivi(vector<nodo> &g)
{
    vector<int> res(g.size(), -1);
    vector<int> id = scc(g);
    for (int i = 0; i < g.size(); i++) {
        for (int vic : g[i].vic) {
            if (id[i] != id[vic]) {
                res[i] = vic;
            }
        }
    }
    return res;
}

void dfs_aux(vector<nodo> &g,
        vector<int> &ab, // num di percorsi da ogni nodo
        vector<bool> &cd, // nodi chiusi
        vector<int> &cat, // cattivi
        vector<bool> &div, // combinazioni diverse
        int cur,
        int b)
{
    g[cur].visitato = true;
    if (cur == b) {
        ab[cur] = 1;
        cd[cur] = true;
        div[cur] = false;
        return;
    }

    for (int vic : g[cur].vic) {
        if (!g[vic].visitato) {
            dfs_aux(g, ab, cd, cat, div, vic, b);
        }
        if (cd[vic]) {
            ab[cur] += ab[vic];
        }
    }
    cd[cur] = true;
}

int dfs(vector<nodo> &g, int a, int b)
{
    // g 1
    vector<int> ab(g.size(), 0); // 2
    vector<bool> cd(g.size(), false); // 3
    vector<int> cat = cattivi(g); // 4
    vector<bool> div(g.size(), true); // 6
    // a 6
    // b 7
    dfs_aux(g, ab, cd, cat, div, a, b);
    for (int i = 0; i < g.size(); i++) {
        cout << i << ": " << div[i] << endl;
    }
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
    return 0;
}
