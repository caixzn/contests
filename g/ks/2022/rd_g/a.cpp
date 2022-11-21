#include <iostream>
#include <vector>
using namespace std;

void solve(void) {
    int m, n, p;
    cin >> m >> n >> p;

    vector<int> max_daily_steps(n);
    vector<int> john_steps(n);
    for (int i = 0; i < m; ++i) {
        if (i == (p - 1)) {
            for (int j = 0; j < n; ++j) {
                cin >> john_steps[j];
                max_daily_steps[j] = max(max_daily_steps[j], john_steps[j]);
            }
            continue;
        }
        for (int j = 0, steps; j < n; ++j) {
            cin >> steps;
            max_daily_steps[j] = max(max_daily_steps[j], steps);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += max(0, max_daily_steps[i]-john_steps[i]);
    }
    cout << ans << '\n';
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}