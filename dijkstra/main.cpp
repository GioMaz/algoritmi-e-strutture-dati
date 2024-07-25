#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int min_dist(vector<vector<int> > &g, vector<int> &dist, vector<bool> &visited)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < g.size(); v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(vector<vector<int> > &g, int u)
{
    // Vector dist
    vector<int> dist(g.size(), INT_MAX);
    dist[u] = 0;

    // Vector visited
    vector<bool> visited(g.size(), false);

    bool finish = false;
    while (!finish) {
        // Find u
        int u = min_dist(g, dist, visited);
        visited[u] = true;

        // Update dist
        finish = true;
        for (int v = 0; v < g.size(); v++) {
            if (!visited[v] && g[u][v]
                // && dist[u] != INT_MAX
                && dist[u] + g[u][v] < dist[v]) {
                dist[v] = dist[u] + g[u][v];
                finish = false;
            }
        }
    }

    for (int i = 0; i < dist.size(); i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main()
{
    ifstream in("input.txt");
    int N, M;
    in >> N >> M;
    vector<vector<int> > g(N, vector<int>(N, 0));
    for (int i = 0; i < M; i++) {
        int t1, t2, t3;
        in >> t1 >> t2 >> t3;
        g[t1][t2] = t3;
        g[t2][t1] = t3;
    }

    // Dijkstra è come una bfs solo che sceglie
    // il percorso con costo inferiore
    dijkstra(g, 0);
}
