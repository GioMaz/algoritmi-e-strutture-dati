#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>

using namespace std;

struct pairhash {
public:
  template <typename T, typename U>
  std::size_t operator()(const std::pair<T, U> &x) const
  {
    return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
  }
};

int sc(vector<int> &a, int n, int m, unordered_map<pair<int, int>, int, pairhash> &dp)
{
    if (n < 0) {
        return 0;
    }

    if (dp[make_pair(n, m)]) {
        // cout << "from " << a[n] << " and " << m << " got " << dp[make_pair(n, m)] << endl;
        return dp[make_pair(n, m)];
    }

    int res;
    if (a[n] < m) {
        res = max(a[n] + sc(a, n-1, a[n], dp), sc(a, n-1, m, dp));
    } else {
        res = sc(a, n-1, m, dp);
    }

    dp[make_pair(n, m)] = res;
    return res;
}

int main()
{
    ifstream in("input.txt");
    int n;
    in >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        in >> a[i];
    }

    unordered_map<pair<int, int>, int, pairhash> dp;
    int res = sc(a, n-1, INT_MAX, dp);
    cout << res << endl;

    ofstream out("output.txt");
    out << res;
    return 0;
}

