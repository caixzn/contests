#include <iostream>
#include <vector>
using namespace std;

void solve(void) {
    int n;
    cin >> n;
    vector<int> a(10);
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        a[x] = 1;
    }
    vector<int> remaining;
    for (int i = 0; i <= 9; ++i) {
        if (!a[i])
            remaining.push_back(i);
    }

    int ans = 0;
    for (int i = 0; i < int(remaining.size()); ++i) {
        for (int j = i + 1; j < int(remaining.size()); ++j)
            ans += 6;
    }
    cout << ans << '\n';
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