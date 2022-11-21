#include <iostream>
#include <vector>
using namespace std;

void solve(void) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto &ai : a)
        cin >> ai;
    for (auto &bi : b)
        cin >> bi;

    if (k == 0) {
        cout << (a == b ? "YES" : "NO");
    } else {
        int eq_idx = -1;
        for (int i = 0; i < n; ++i) {
            if (a[i] == b[0]) {
                eq_idx = i;
                break;
            }
        }
        if (eq_idx == -1 || (k == 1 && eq_idx == 0))
            cout << "NO";
        else {
            vector<int> c(n);
            int i = 0, eq_idx_cpy = eq_idx;
            while (i < n && eq_idx < n) {
                c[i] = a[eq_idx++];
                if (c[i] != b[i]) {
                    cout << "NO";
                    return;
                }
                ++i;
            }
            for (int j = 0; j < eq_idx_cpy; ++j, ++i) {
                c[i] = a[j];
                if (c[i] != b[i]) {
                    cout << "NO";
                    return;
                }
            }
            cout << "YES";
        }
    }
    
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << '\n';
    }
    return 0;
}