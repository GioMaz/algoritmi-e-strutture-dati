#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream in("input.txt");
    int T;
    in >> T;

    ofstream out("output.txt");
    for (int i = 0; i < T; i++) {
        int N, K;
        in >> N >> K;
        vector<int> v;
        for (int j = 0; j < N; j++) {
            int tmp;
            in >> tmp;
            if (!v.empty() && tmp == v.back()) {
                v.pop_back();
            } else {
                v.push_back(tmp);
            }
        }

        if (v.size() == 0) {
            out << 1 << endl;
        } else {
            out << 0 << endl;
        }
    }

    return 0;
}
