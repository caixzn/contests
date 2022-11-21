#include <iostream>
#include <vector>
using namespace std;

void solve(void) {
    int n;
    cin >> n;
    vector<int> a(n);

    int j = 1;
    for (int i = !(n&1); i < n; i+=2)
        a[i] = j++;
    for (int i = n&1; i < n; i+=2)
        a[i] = j++;
    
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