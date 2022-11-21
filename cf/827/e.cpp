#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(void) {
    long long n, q;
    cin >> n >> q;

    vector<long long> a(n);
    for (auto &ai : a) {
        cin >> ai;
    }

    vector<long long> a_sum(n), a_max(n);
    a_sum[0] = a[0];
    a_max[0] = a[0];
    for (long long i = 1; i < n; ++i) {
        a_sum[i] = a_sum[i-1] + a[i];
        a_max[i] = max(a_max[i-1], a[i]);
    }

    long long k;
    while (q--) {
        cin >> k;
        auto it = upper_bound(a_max.begin(), a_max.end(), k);
        int idx = it - a_max.begin() - 1;
        if (idx < 0)
            cout << 0;
        else
            cout << a_sum[idx];
        cout << ' ';
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