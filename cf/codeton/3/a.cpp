#include <iostream>
#include <vector>
using namespace std;

void solve(void) {
    int n;
    cin >> n;
    vector<int> a(n);
    int mn = 11;
    for (auto &ai : a) {
        cin >> ai;
        mn = min(mn, ai);
    }

    if (a[0] != mn) {
        cout << "no\n";
        return;
    }
    cout << "yes\n";
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