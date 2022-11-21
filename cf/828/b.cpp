#include <iostream>
using namespace std;

void solve(void) {
    int n, q;
    cin >> n >> q;
    long long qty[2] = {0}, num;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        ++qty[num&1];
        sum += num;
    }

    bool type;
    long long x;
    while (q--) {
        cin >> type >> x;
        sum += qty[type]*x;
        if (x & 1) {
            qty[!type] += qty[type];
            qty[type] = 0;
        }
        cout << sum << '\n';
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