#include <iostream>
using namespace std;

void solve(void) {
    int n, k;
    cin >> n >> k;

    bool ans = false;
    for (int i = 0, ai; i < n; ++i) {
        cin >> ai;
        if (!ans && ai)
            ans = true;
    }

    cout << (ans ? "YES" : "NO") << '\n';
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