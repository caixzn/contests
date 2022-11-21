#include <iostream>
#include <vector>
using namespace std;

void solve(void) {
    int n, m;
    cin >> n >> m;
    char col[n] = {0}, row[n] = {0};
    vector<pair<int, int>> pos;
    int x, y;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        ++row[x - 1], ++col[y - 1];
        pos.emplace_back(x - 1, y - 1);
    }
    bool ok = false;
    for (const auto &[x0, y0] : pos) {
        for (int i = 0; i < n && col[y0] <= 1; ++i) {
            if (i == x0)
                continue;
            if (row[i] == 0) {
                ok = true;
                break;
            }
        }
        if (ok)
            break;
        for (int i = 0; i < n && row[x0] <= 1; ++i) {
            if (i == y0)
                continue;
            if (col[i] == 0) {
                ok = true;
                break;
            }
        }
        if (ok)
            break;
    }
    cout << (ok ? "YES" : "NO") << '\n';
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