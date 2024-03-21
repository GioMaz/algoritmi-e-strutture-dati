#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

struct nodo {
    vector<int> vic;
};

int mc(vector<nodo> &t, int u, bool taken, vector<vector<int> > &dp)
{
    if (dp[u][taken] < 0) {
        if (taken) {
            int res1 = 0;
            for (int v : t[u].vic) {
                res1 += mc(t, v, false, dp);
            }

            int res2 = 1;
            for (int v : t[u].vic) {
                res2 += mc(t, v, true, dp);
            }

            dp[u][taken] = min(res1, res2);
        } else {
            int res = 1;
            for (int v : t[u].vic) {
                res += mc(t, v, true, dp);
            }
            dp[u][taken] = res;
        }
    }

    return dp[u][taken];
}

int main()
{
    ifstream in("input.txt");
    int N;
    in >> N;

    vector<nodo> t(N);
    for (int i = 0; i < N-1; i++) {
        int tmp1, tmp2;
        in >> tmp1 >> tmp2;
        t[tmp1].vic.push_back(tmp2);
    }

    // for (int u = 0; u < N; u++) {
    //     cout << u;
    //     for (int v = 0; v < t[u].vic.size(); v++) {
    //         cout << t[u].vic[v];
    //     }
    //     cout << endl;
    // }

    vector<vector<int> > dp(t.size(), vector<int>(2, -1));
    int res = mc(t, 0, true, dp);
    cout << res << endl;
    ofstream out("output.txt");
    out << res;

    return 0;
}
