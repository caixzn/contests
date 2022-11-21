#include <iostream>
#include <unordered_set>
using namespace std;

void solve(void) {
    int n;
    cin >> n;

    bool yes = true;
    unordered_set<int> a(n);
    for (int i = 0, num; i < n; ++i) {
        cin >> num;
        auto [it, ok] = a.insert(num);
        if (!ok) {
            yes = false;
        }
    }

    cout << (yes ? "YES" : "NO") << '\n';
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