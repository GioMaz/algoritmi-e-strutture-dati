#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

struct nodo {
    vector<int> vic;
    bool visitato = false;
};

int visita(vector<nodo> grafo, int n)
{
    int res = 1;

    queue<int> q;
    q.push(n);
    grafo[n].visitato = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int vic : grafo[cur].vic) {
            if (!grafo[vic].visitato) {
                grafo[vic].visitato = true;
                q.push(vic);
                res++;
            }
        }
    }

    return res;
}

int main()
{
    ifstream in("input.txt");
    int N, M, S;
    in >> N >> M >> S;

    vector<nodo> grafo(N);
    for (int i = 0; i < M; i++) {
        int tmp1, tmp2;
        in >> tmp1 >> tmp2;
        grafo[tmp1].vic.push_back(tmp2);
    }

    // for (int i = 0; i < N; i++) {
    //     cout << i << ": ";
    //     for (int j = 0; j < grafo[i].vic.size(); j++) {
    //         cout << grafo[i].vic[j] << " ";
    //     }
    //     cout << endl;
    // }

    int res = visita(grafo, S);
    ofstream out("output.txt");
    out << res;

    return 0;
}
