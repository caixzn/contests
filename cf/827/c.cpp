#include <iostream>
#include <vector>
using namespace std;

void solve(void) {
    vector<string> grid(8);
    for (int i = 0; i < 8; ++i)
        cin >> grid[i];
    for (int i = 0, cnt; i < 8; ++i) {
        cnt = 0;
        for (const auto &c : grid[i])
            if (c == 'R') ++cnt;
        if (cnt == 8) {
            cout << "R\n";
            return;
        }
    }
    cout << "B\n";
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