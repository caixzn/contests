#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve(void) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    long long ans = 0;
    for (auto &ai : a) {
        cin >> ai;
        ans += ai;
    }
    for (auto &bi : b) {
        cin >> bi;
        ans += bi;
    }
    int mx = -1;
    for (const auto &bi : b) {
        mx = max(mx, bi);
    }
    ans -= mx;
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