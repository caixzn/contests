#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <forward_list>
using namespace std;
using pii = pair<int, int>;

constexpr int infty = 1000000000;

struct node {
    int id, time;
};

void dijkstra(vector<int>& cost, vector<int>& pi, const vector<vector<node>>& g, const int &start, const int initial_cost = 0) {
    vector<bool> visited(cost.size());
    cost[start] = initial_cost;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({initial_cost, start});
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (visited[u])
            continue;
        visited[u] = true;
        for (const auto &n : g[u]) {
            if (visited[n.id])
                continue;
            if (d + n.time < cost[n.id]) {
                pi[n.id] = u;
                cost[n.id] = d + n.time;
                pq.push({cost[n.id], n.id});
            }
        }
    }
}

vector<vector<node>> initial_paths;
void dfs(const vector<vector<node>> &g, vector<node> &path, int dist = 0, int depth = 1, int id = 1) {
    if (depth == 5) {
        initial_paths.push_back(path);
        return;
    }

    int best_dist = infty, best_id = infty;
    for (const auto &n : g[id]) {
        bool ok = true;
        for (const auto &[ii, tt] : path)
            if (ii == n.id) ok = false;
        if (ok) {
            path.push_back(n);
            dfs(g, path, dist + n.time, depth + 1, n.id);
            path.pop_back();
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<node>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int id_a, id_b, time;
        cin >> id_a >> id_b >> time;
        graph[id_a].push_back({id_b, time});
        graph[id_b].push_back({id_a, time});
    }
    // int ans;
    // int lower = 0, upper = infty, mid;
    // while (lower <= upper) {
    //     mid = (upper&lower) + ((upper^lower)>>1);
        // if (cost[end] != infty) {
        //     save_path(path, pi, end);
        //     upper = mid - 1;
        //     ans_dist = cost[end];
        //     ans_temp = mid;
        //     continue;
        // }
        // lower = mid + 1;
    vector<node> path;
    path.push_back({1, 0});
    path.reserve(5);
    dfs(graph, path);
    for (int i = 1; i <= n; ++i) {
        int ans = infty;
        for (const auto &pth : initial_paths) {
            int initial_cost = 0;
            for (const auto &t : pth)
                initial_cost += t.time;
            int start = pth.back().id;
            if (start == i) {
                vector<int> cost(n + 1, infty);
                vector<int> pi(n + 1, -1);
                for (const auto &n : graph[i]) {
                    bool ok = true;
                    for (const auto &nn : path)
                        if (nn.id == n.id) ok = false;
                    if (!ok) continue;
                    dijkstra(cost, pi, graph, n.id, initial_cost + n.time);
                    ans = min(ans, cost[i]);
                }
            } else {
                vector<int> cost(n + 1, infty);
                vector<int> pi(n + 1, -1);
                dijkstra(cost, pi, graph, start, initial_cost);
                ans = min(ans, cost[i]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}