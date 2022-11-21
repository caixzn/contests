#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(void) {
    int n, a, b;
    cin >> n >> a >> b;
    if (a == n && b == n) {
        cout << "Yes\n";
    } else if (n - a - b < 2) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
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
