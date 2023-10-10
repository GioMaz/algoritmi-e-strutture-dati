#include <iostream>
#include <fstream>

using namespace std;


int main()
{
    int N;
    ifstream in("input.txt");
    in >> N;
    int a[N];

    for (int i = 0; i < N; i++) {
        in >> a[i];
    }
    cout << endl;

    int aapp[N];
    for (int i = 0; i < N; i++) {
        int tmp;
        if (i == 0)
            tmp = a[0];
        else
            tmp = aapp[i-1] + a[i];

        if (tmp < 0)
            tmp = 0;

        aapp[i] = tmp;
    }

    ofstream out("output.txt");
    int max = 0;
    for (int i = 0; i < N; i++) {
        if (aapp[i] > max)
            max = aapp[i];
    }

    out << max;

    return 0;
}

