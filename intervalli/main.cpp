#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ifstream in("input.txt");

    int N;
    in >> N;

    vector<pair<int,int> > a(N);
    for (int i = 0; i < N; i++) {
        in >> a[i].first;
        in >> a[i].second;
    }

    // merge_sort(a, 0, N-1);
    sort(a.begin(), a.end());

    int N1 = 1;
    vector<pair<int,int> > v;
    v.push_back(a[0]);
    // cout << a[0].first << " " << a[0].end << endl;
    for (int i = 1; i < N; i++) {
        pair<int,int> prec = v.back();
        if (a[i].first > prec.first && a[i].second < prec.second) {
        } else {
            v.push_back(a[i]);
            N1++;
            // cout << a[i].first << " " << a[i].second << endl;
        }
    }

    int next = v[0].second;
    int max = -1;
    int r1, r2;
    r1 = r2 = 0;
    for (int i = 0; i < N1-1; i++) {
        if (v[i].second > next) {
            next = v[i].second;
            // cout << next << endl;
        }

        if (v[i].second < v[i+1].first) {
            // cout << v[i].second << " " << v[i+1].first << endl;
            if (v[i].second >= next) {
                // cout << v[i].second << " " << v[i+1].first << endl;
                int cmax = v[i+1].first - v[i].second;
                if (cmax > max) {
                    max = cmax;
                    r1 = v[i].second;
                    r2 = v[i+1].first;
                }
            }
        }
    }

    // cout << r1 << endl;
    // cout << r2 << endl;
    // cout << max << endl;

    ofstream out("output.txt");
    if (r1 == r2 && r2 == 0) {
        out << 0;
    } else {
        out << r1 << " " << r2;
    }

    return 0;
}
