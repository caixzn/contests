#include <iostream>
#include <set>
using namespace std;

void solve(void) {
    int n;
    cin >> n >> ws;
    int mx = -1;
    for (int i = 0; i < n; ++i) {
        char c = cin.get();
        mx = max(mx, (int)c);
    }
    cout << mx - 'a' + 1 << '\n';
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
