#include <iostream>
#include <vector>
using namespace std;

void solve(void) {
    int q;
    cin >> q;
    int d, k;
    string x;
    bool only_a[] = {true, true};
    int64_t a[] = {1, 1};
    while (q--) {
        cin >> d >> k >> x;
        for (const auto& c : x) {
            if (c == 'a')
                a[d-1] += k;
            else if (only_a[d-1])
                only_a[d-1] = false;
        }
        
        if (!only_a[1] || (only_a[0] && only_a[1] && a[0] < a[1]))
            cout << "YES\n";
        else
            cout << "NO\n";
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