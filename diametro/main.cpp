#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

struct nodo {
    vector<int> vic;
    bool visitato = false;
};

vector<int> get_dist(vector<nodo> grafo, int n)
{
    vector<int> dist(grafo.size());
    for (int i = 0; i < grafo.size(); i++) {
        dist[i] = -1;
    }

    queue<int> q;
    q.push(n);
    dist[n] = 0;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int vic : grafo[cur].vic) {
            if (dist[vic] == -1) {
                dist[vic] = dist[cur] + 1;
                q.push(vic);
            }
        }
    }

    return dist;
}

int main()
{
    ifstream in("input.txt");
    int N, M;
    in >> N >> M;

    vector<nodo> grafo(N);
    for (int i = 0; i < M; i++) {
        int tmp1, tmp2;
        in >> tmp1 >> tmp2;
        grafo[tmp1].vic.push_back(tmp2);
        grafo[tmp2].vic.push_back(tmp1);
    }

    int res = -1;
    for (int n = 0; n < N; n++) {
        vector<int> dist = get_dist(grafo, n);

        for (int d : dist) {
            res = max(res, d);
        }
    }

    ofstream out("output.txt");
    out << res;

    return 0;
}
