#include <iostream>
#include <map>
#include <list>
using namespace std;

int highest = 1;

void dfs(map<int, bool> &vis, map<int, list<int>> &g, const int id = 1) {
    if (g.find(id) == g.end())
        return;
    vis[id] = true;
    highest = max(highest, id);
    list<int> &neighbors = g[id];
    for (const auto &node : neighbors) {
        if (!vis[node]) {
            dfs(vis, g, node);
            vis[node] = true;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    map<int, list<int>> g;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    map<int, bool> vis;
    dfs(vis, g);
    cout << highest << '\n';
    return 0;
}
