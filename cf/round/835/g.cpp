#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

struct node {
    list<int> neighbors;
    int w;
};

bool bfs(vector<node> &g, int start, int end) {
    vector<bool> vis(g.size());
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == end) return true;
        vis[u] = true;
        for (const auto &v : g[u].neighbors)
            if (!vis[v] && g[v].w == g[u].w)
                q.push(v);
    }
    return false;
}

void solve(void) {
    int n, start, goal;
    cin >> n >> start >> goal;
    int goal_wt;
    vector<node> g(n+1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        if (u == goal) {
            goal_wt = w;
            continue;
        }
        g[u].neighbors.push_back(v);
        g[u].w = w;
        g[v].neighbors.push_back(u);
    }
    cout << (bfs(g, start, g[goal].w) ? "YES\n" : "NO\n");
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
