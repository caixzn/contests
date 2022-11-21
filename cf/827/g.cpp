#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

void solve(void) {
    int n;
    cin >> n;
    vector<uint32_t> a(n);
    uint32_t or_val = 0, max_idx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > or_val) {
            or_val = a[i];
            max_idx = i;
        }
    }
    swap(a[0], a[max_idx]);

    int msb = 32 - __builtin_clz(or_val);
    uint32_t max_val = (1 << msb) - 1;
    for (int i = 0; i < min(n - 1, msb - 1); ++i) {
        if (or_val == max_val) break;
        uint32_t max_or = or_val;
        max_idx = i + 1;
        for (int j = i + 1; j < n; ++j) {
            if ((or_val|a[j]) > max_or) {
                max_or = or_val | a[j];
                max_idx = j;
            }
        }
        or_val = max_or;
        swap(a[i+1], a[max_idx]);
    }

    for (const auto &x : a)
        cout << x << ' ';
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