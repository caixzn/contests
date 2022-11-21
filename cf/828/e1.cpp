#include <iostream>
#include <algorithm>
using namespace std;

void solve(void) {
    int64_t a, b, c, d;
    cin >> a >> b >> c >> d;

    int64_t ab = a*b;
    pair<int64_t, int64_t> ans = {-1, -1};
    for (int64_t i = a + 1, gcd; i <= c; ++i) {
        gcd = __gcd(i, ab);
        if (gcd > b && gcd <= d) {
            ans = {i, gcd};
        }
    }

    cout << ans.first << ' ' << ans.second << '\n';
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