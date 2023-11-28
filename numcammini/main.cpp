#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

struct nodo {
    vector<int> vic;
    bool visitato = false;
};

vector<int> get_dist(vector<nodo> grafo, int a)
{
    vector<int> dist(grafo.size(), -1);
    queue<int> q;
    q.push(a);
    dist[a] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int vic : grafo[cur].vic) {
            if (dist[vic] == -1) {
                dist[vic] = dist[cur]+1;
                q.push(vic);
            }
        }
    }

    return dist;
}

pair<int, int> nc(vector<nodo> g1, vector<nodo> g2, int a, int b)
{
    vector<int> d1 = get_dist(g1, a);
    vector<int> d2 = get_dist(g2, b);
    int d = d1[b];

    vector<int> dist(d1.size(), -1);

    queue<int> q;
    q.push(a);
    dist[a] = 0;

    int res = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int vic : g1[cur].vic) {
            if (dist[vic] == -1) {
                dist[vic] = dist[cur]+1;
                q.push(vic);
            } else if (d1[cur]+d2[cur] == d
                    && d1[vic]+d2[vic] == d
                    && d1[cur]+1 == d1[vic]) {
                res++;
            }
        }
    }

    return make_pair(d, res);
}

int main()
{
    ifstream in("input.txt");
    int N, M, a, b;
    in >> N >> M >> a >> b;
    vector<nodo> g1(N);
    vector<nodo> g2(N);
    for (int i = 0; i < M; i++) {
        int tmp1, tmp2;
        in >> tmp1 >> tmp2;
        g1[tmp1].vic.push_back(tmp2);
        g2[tmp2].vic.push_back(tmp1);
    }

    pair<int, int> res = nc(g1, g2, a, b);

    ofstream out("output.txt");
    cout << max(0, res.first) << " " << res.second << endl;

    return 0;
}
