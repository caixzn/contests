#include <iostream>
#include <map>
#include <queue>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    map<int, priority_queue<int, vector<int>, greater<int>>> graph;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].emplace(b);
        graph[b].emplace(a);
    }
    for (int i = 1; i <= n; ++i) {
        if (graph.find(i) == graph.end()) {
            cout << 0;
        } else {
            auto &pq = graph[i];
            cout << pq.size();
            do {
                cout << ' ' << pq.top();
                pq.pop();
            } while (!pq.empty());
        }
        cout << '\n';
    }
    return 0;
}