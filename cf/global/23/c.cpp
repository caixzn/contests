#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void f() {}

void solve(void) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<pair<int, int>> diff;
    for (int i = 0; i < n - 1; ++i)
        diff.emplace_back(a[i] - a[i+1], i + 1);

    sort(diff.begin(), diff.end());

    cout << 1;

    for (const auto &[val, idx] : diff) {
        cout << ' ' << idx + 1;
    }

    cout << '\n';
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