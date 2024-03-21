#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

long long pill(long long i, long long m, vector<vector<long long> > &dp)
{
    if (i == 0 && m == 0) {
        return 0;
    }
    if (i == 0 && m == 1) {
        return 1;
    }

    long long res = 0;
    if (i > 0) {
        if (dp[i-1][m+1] > 0) {
            res += dp[i-1][m+1];
        } else {
            dp[i-1][m+1] = pill(i-1, m+1, dp);
            res += dp[i-1][m+1];
        }
    }
    if (m > 0) {
        if (dp[i][m-1] > 0) {
            res += dp[i][m-1];
        } else {
            dp[i][m-1] = pill(i, m-1, dp);
            res += dp[i][m-1];
        }
    }
    return res;
}

int main()
{
    ifstream in("input.txt");
    long long i;
    in >> i;

    vector<vector<long long> > dp(i, vector<long long>(i*2, -1));
    long long res = pill(i, 0, dp);

    // cout << res << endl;

    ofstream out("output.txt");
    out << res;
    return 0;
}
