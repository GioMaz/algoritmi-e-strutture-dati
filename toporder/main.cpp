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
    for (int i = 0; i < s.size()/2; i++) {
        swap(s[i], s[s.size()-i-1]);
    }
    return s;
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

    vector<int> s = ts(g);
    ofstream out("output.txt");
    for (int i : s) {
        out << i << " ";
    }

    return 0;
}
