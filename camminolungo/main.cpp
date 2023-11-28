#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

struct nodo {
    vector<int> vic;
    bool visitato = false;
};

void tsdfs(vector<nodo> &g, vector<int> &s, int i)
{
    g[i].visitato = true;
    for (int vic : g[i].vic) {
        if (!g[vic].visitato) {
            tsdfs(g, s, vic);
        }
    }
    s.push_back(i);
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

void dfs(vector<nodo> &g, vector<int> &dist, int cur)
{
    for (int vic : g[cur].vic) {
        if (dist[vic] == -1) {
            dist[vic] = dist[cur]+1;
            dfs(g, dist, vic);
        } else if (dist[vic] < dist[cur]+1) {
            dist[vic] = dist[cur]+1;
            dfs(g, dist, vic);
        }
    }
}

int cl(vector<nodo> &g)
{
    int res = 0;
    for (int i = 0; i < g.size(); i++) {
        vector<int> dist(g.size(), -1);
        dist[i] = 0;
        dfs(g, dist, i);
        for (int d : dist)
            res = max(res, d);
    }
    return res;
    // TS (non tiene conto delle componenti connesse)
    // int r = ts(g).back();

    // vector<int> dist(g.size(), -1);
    // dist[r] = 0;
    // dfs(g, dist, r);

    // int res = 0;
    // for (int d : dist) {
    //     res = max(res, d);
    // }
    // return res;
}

int main()
{
    ifstream in("input.txt");
    int N, M;
    in >> N >> M;

    vector<nodo> g(N);
    for (int i = 0; i < M; i++) {
        int tmp1, tmp2;
        in >> tmp1 >> tmp2;
        g[tmp1].vic.push_back(tmp2);
    }

    int res = cl(g);
    ofstream out("output.txt");
    out << res;

    return 0;
}
