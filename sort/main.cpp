#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

void print(int *a, int dim)
{
    for (int i = 0;i < dim; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void merge(int *a, int start, int m, int end)
{
    int i = start;
    int j = m+1;
    int k = 0;

    int *c = new int[end-start+1];
    while (i <= m && j <= end) {
        if (a[i] < a[j]) {
            c[k] = a[i];
            i++;
        } else {
            c[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= m) {
        c[k] = a[i];
        i++;
        k++;
    }

    while (j <= end) {
        c[k] = a[j];
        j++;
        k++;
    }

    for (int i = 0; i < k; i++) {
        a[start+i] = c[i];
    }

    delete[] c;
}

void merge_sort(int *a, int start, int end)
{
    if (start < end) {
        int m = (start + end) / 2;
        // cout << start << " " << m << " " << end << endl;
        merge_sort(a, start, m);
        merge_sort(a, m+1, end);
        merge(a, start, m, end);
    }
}

int main()
{
    ifstream in("input.txt");

    int N;
    in >> N;

    int a[N];
    for (int i = 0; i < N; i++) {
        in >> a[i];
    }

    merge_sort(a, 0, N-1);

    ofstream out("output.txt");
    for (int i = 0; i < N; i++) {
        out << a[i] << " ";
    }

    return 0;
}
