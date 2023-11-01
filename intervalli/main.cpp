#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

typedef struct {
    int start;
    int end;
} Couple;

bool lessCouple(Couple a, Couple b) {
    if (a.start == b.start) {
        return a.end < b.end;
    } else {
        return a.start < b.start;
    }
}

int main()
{
    ifstream in("input.txt");

    int N;
    in >> N;

    vector<Couple> a(N);
    for (int i = 0; i < N; i++) {
        in >> a[i].start;
        in >> a[i].end;
    }

    // merge_sort(a, 0, N-1);
    sort(a.begin(), a.end(), lessCouple);

    int N1 = 1;
    vector<Couple> v;
    v.push_back(a[0]);
    // cout << a[0].start << " " << a[0].end << endl;
    for (int i = 1; i < N; i++) {
        Couple prec = v.back();
        if (a[i].start > prec.start && a[i].end < prec.end) {
        } else {
            v.push_back(a[i]);
            N1++;
            // cout << a[i].start << " " << a[i].end << endl;
        }
    }

    int next = v[0].end;
    int max = -1;
    int r1, r2;
    r1 = r2 = 0;
    for (int i = 0; i < N1-1; i++) {
        if (v[i].end > next) {
            next = v[i].end;
            // cout << next << endl;
        }

        if (v[i].end < v[i+1].start) {
            // cout << v[i].end << " " << v[i+1].start << endl;
            if (v[i].end >= next) {
                // cout << v[i].end << " " << v[i+1].start << endl;
                int cmax = v[i+1].start - v[i].end;
                if (cmax > max) {
                    max = cmax;
                    r1 = v[i].end;
                    r2 = v[i+1].start;
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
