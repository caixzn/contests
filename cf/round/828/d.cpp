#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(void) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    vector<int> fac_i(n);
    int fac_needed = n;
    for (int i = 0; i < n; ++i) {
        fac_needed -= __builtin_ctz(a[i]);
        fac_i[i] = __builtin_ctz(i+1);
    }

    if (fac_needed > 0) {
        sort(fac_i.rbegin(), fac_i.rend());
        int op = 1;
        for (const auto &fac : fac_i) {
            fac_needed -= fac;
            if (fac_needed <= 0) break;
            ++op;
        }
        cout << (fac_needed > 0 ? -1 : op) << '\n'; 
    } else {
        cout << "0\n";
    }
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