#include <fstream>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int zaino(vector<int> &p, vector<int> &v, int n, int c, vector<vector<int> > &dp)
{
    if (c < 0) {
        return INT_MIN;
    }
    if (c == 0) {
        return 0;
    }
    if (n < 0) {
        return 0;
    }

    if (dp[n][c] < 0) {
        int res = max(v[n] + zaino(p, v, n-1, c-p[n], dp), zaino(p, v, n-1, c, dp));
        dp[n][c] = res;
    }

    return dp[n][c];
}

int main()
{
    ifstream in("input.txt");
    int C, N;
    in >> C >> N;
    vector<int> p(N);
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        in >> p[i];
        in >> v[i];
    }

    vector<vector<int> > dp(N, vector<int>(C+1, -1));
    int res = zaino(p, v, N-1, C, dp);
    cout << res << endl;

    ofstream out("output.txt");
    out << res;
    return 0;
}
