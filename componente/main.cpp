#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

struct nodo {
    vector<int> vic;
    bool visitato = false;
};

void tsdfs(vector<nodo> &grafo, vector<int> &s, int n)
{
    grafo[n].visitato = true;
    for (int vic : grafo[n].vic) {
        if (!grafo[vic].visitato) {
            tsdfs(grafo, s, vic);
        }
    }
    s.push_back(n);
}

vector<int> ts(vector<nodo> &grafo)
{
    vector<int> s;
    for (int i = 0; i < grafo.size(); i++) {
        if (!grafo[i].visitato) {
            tsdfs(grafo, s, i);
        }
    }
    return s;
}

vector<nodo> transpose(vector<nodo> &grafo)
{
    vector<nodo> gt(grafo.size());
    for (int i = 0; i < grafo.size(); i++) {
        for (int vic : grafo[i].vic) {
            gt[vic].vic.push_back(i);
        }
    }
    return gt;
}

void ccdfs(vector<nodo> &gt, vector<int> &id, int counter, int i)
{
    id[i] = counter;
    for (int vic : gt[i].vic) {
        if (id[vic] == 0) {
            ccdfs(gt, id, counter, vic);
        }
    }
}

vector<int> cc(vector<nodo> &gt, vector<int> &s)
{
    vector<int> id(gt.size());
    int counter = 0;
    while (!s.empty()) {
        int cur = s.back();
        s.pop_back();
        if (id[cur] == 0) {
            counter++;
            ccdfs(gt, id, counter, cur);
        }
    }
    return id;
}

vector<int> scc(vector<nodo> &grafo)
{
    vector<int> s = ts(grafo);
    vector<nodo> gt = transpose(grafo);
    return cc(gt, s);
}

int maxcc(vector<nodo> &grafo)
{
    vector<int> id = scc(grafo);
    vector<int> cccount(grafo.size(), 0);
    for (int i : id) {
        cccount[i]++;
    }
    int res = 0;
    for (int i : cccount) {
        res = max(res, i);
    }
    return res;
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
    }

    int res = maxcc(grafo);

    ofstream out("output.txt");
    out << res;

    return 0;
}
