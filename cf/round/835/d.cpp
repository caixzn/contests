#include <iostream>
#include <vector>
using namespace std;

void solve(void) {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (i == 0 || x != a.back()) {
            a.push_back(x);
        }
    }
    n = int(a.size());
    int valley = 0;
    for (int i = 0; i < n; ++i)
        if ((i == 0 || a[i-1] > a[i]) && (i == n - 1 || a[i] < a[i+1]))
            ++valley;
    if (valley == 1) cout << "yes\n";
    else cout << "no\n";
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
