#include <iostream>
#include <algorithm>
using namespace std;

void solve(void) {
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(begin(a), end(a));
    cout << a[1] << '\n';
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
