#include <forward_list>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

constexpr int infty = 1000000000;

// A Dynamic programming based function to find the shortest path from
// u to v with exactly k edges.
int shortestPath(vector<vector<int>> &g, int dest) {
    const int k = 5;
    const int V = (int)g.size() - 1;
    // Table to be filled up using DP. The value sp[i][j][e] will store
    // weight of the shortest path from i to j with exactly k edges
    vector<vector<vector<int>>> table (V+1, vector<vector<int>>(V+1, vector<int>(V+1)));

    // Loop for number of edges from 0 to k
    for (int e = 0; e <= V; ++e) {
        for (int i = 1; i <= 1; ++i) {
            for (int j = 1; j <= V; ++j) {
                // initialize value
                table[1][j][e] = infty;

                // from base cases
                if (e == 0 && i == j)
                    table[i][j][e] = 0;
                if (e == 1 && g[i][j] != infty)
                    table[i][j][e] = g[i][j];

                // go to adjacent only when number of edges is more than 1
                if (e > 1) {
                    for (int a = 0; a < V; ++a) {
                        // There should be an edge from i to a and a
                        // should not be same as either i or j
                        if (g[i][a] != infty && i != a && j != a &&
                            table[a][j][e - 1] != infty)
                            table[i][j][e] =
                                min(table[i][j][e], g[i][a] + table[a][j][e - 1]);
                    }
                }
            }
        }
    }
    while (table[1][dest][k] == infty) ++dest;
    return table[1][dest][k];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, infty));
    for (int i = 0; i < m; ++i) {
        int src, dest, time;
        cin >> src >> dest >> time;
        graph[src][dest] = time;
        graph[dest][src] = time;
    }

    for (int i = 1; i <= n; ++i) {
        cout << shortestPath(graph, i) << '\n';
    }
    return 0;
}