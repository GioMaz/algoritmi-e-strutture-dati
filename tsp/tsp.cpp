#include <iostream>
#include <climits>
#include <fstream>
#include <vector>

#include "tsp.h"

using namespace std;

struct nodo {
    vector<int> adj;
    bool visited = false;
};

int next(vector<vector<int>> &g, vector<bool> &visited, int u)
{
    int mind = INT_MAX;
    int minv = -1;
    int mindvisited = INT_MAX;
    int minvvisited = -1;
    for (int i = 0; i < g.size(); i++) {
        if (g[u][i] != 0) { // Se vicini
            if (visited[i]) {
                if (g[u][i] < mindvisited) {
                    minvvisited = i;
                    mindvisited = g[u][i];
                }
            } else { // Se non visitato
                if (g[u][i] < mind) { // Se minore dell'attuale
                    minv = i;
                    mind = g[u][i];
                }
            }
        }
    }

    if (minv > -1) {
        return minv;
    } else {
        return minvvisited;
    }
}

bool completed(vector<bool> &visited)
{
    for (int i = 0; i < visited.size(); i++) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}

void greedy(vector<vector<int>> &g, int u, ofstream &out)
{
    vector<bool> visited(g.size(), false);
    int first = u;
    visited[u] = true;

    out << "0 ";
    while (!completed(visited)) {
        u = next(g, visited, u);
        visited[u] = true;
        out << u << " ";
    }
    out << first << "#";
}

bool should_switch(vector<vector<int>> &g, vector<int> &res, int u, int v)
{
    int ul = res[u-1];
    int um = res[u];
    int ur = res[u+1];
    int vl = res[v-1];
    int vm = res[v];
    int vr = res[v+1];
    if (g[ul][vm] + g[vm][ul] + g[vl][um] + g[um][vr]
        < g[ul][um] + g[um][ur] + g[vl][vm] + g[vm][vr]) {
        return true;
    }
    return false;
}

void ls(vector<vector<int>> &g, ofstream &out)
{
    vector<int> res(g.size() + 2);
    res[0] = 0;
    for (int i = 1; i < g.size() + 1; i++) {
        res[i] = i;
    }
    res[g.size()+1] = 0;
    for (int i = 0; i < res.size(); i++) {
        cout << " " << res[i];
    }

    while (1) {
        // 0 1 2 3 4 0
        int u = (rand() % (res.size() - 2)) + 1;
        int v = (rand() % (res.size() - 2)) + 1;
        if (u != v && should_switch(g, res, u, v)) {
            // cout << u1 << v1 << " " << u2 << v2 << endl;
            swap(res[u], res[v]);

            // Print
            out << "\n";
            for (int i = 0; i < g.size(); i++) {
                out << " " << res[i];
            }
            out << " 0#";
        }
    }
}

int main()
{
    ifstream in("input.txt");
    int N;
    in >> N;
    vector<vector<int> > g(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int w;
            in >> w;
            g[i][j] = w;
            g[j][i] = w;
        }
    }

    ofstream out("output.txt");
    greedy(g, 0, out);

    return 0;
}
