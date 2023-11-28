#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

vector<int> solve(vector<pair<char,int>> v)
{
    if (v.size() == 1) {
        return {v[0].second};
    } else {
        vector<int> res;
        for (int i = 1; i < v.size()-1; i++) {
            vector<pair<char,int>> nv;
            if (v[i].second == 's') {
                for (int j = 0; j < i-1; j++) {
                    nv.push_back(v[j]);
                }
                for (int j = i+1; j < v.size(); j++) {
                    nv.push_back(v[j]);
                }
            } else {
                for (int j = 0; j < i; j++) {
                    nv.push_back(v[j]);
                }
                for (int j = i+2; j < v.size(); j++) {
                    nv.push_back(v[j]);
                }
            }
            vector<int> pres = solve(nv);
            res.insert(res.end(), pres.begin(), pres.end());
        }
        return res;
    }
}

int main()
{
    ifstream in("input.txt");
    int N;
    in >> N;

    vector<pair<char,int>> v(N);
    for (int i = 0; i < N; i++) {
        in >> v[i].first;
        v[i].second = i;
    }

    for (int i = 0; i < N; i++) {
        cout << v[i].first << v[i].second << endl;
    }

    vector<int> res = solve(v);
    for (int r : res) {
        cout << r << endl;
    }

    ofstream out("output.txt");

    return 0;
}
