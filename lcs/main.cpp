#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>

using namespace std;

int lcs(string a, string b, int i, int j, vector<vector<int> > &dp)
{
    if (i < 0)
        return 0;

    if (j < 0)
        return 0;

    if (dp[i][j] < 0) {
        if (a[i] == b[j]) {
            dp[i][j] = lcs(a, b, i-1, j-1, dp) + 1;
        } else {
            dp[i][j] = max(lcs(a, b, i, j-1, dp), lcs(a, b, i-1, j, dp));
        }
    }

    return dp[i][j];
}

int main()
{
    ifstream in("input.txt");
    string a, b;
    in >> a >> b;

    vector<vector<int> > dp(a.size(), vector<int>(b.size(), -1));
    int res = lcs(a, b, a.size()-1, b.size()-1, dp);
    cout << res << endl;

    ofstream out("output.txt");
    out << res;
    return 0;
}

