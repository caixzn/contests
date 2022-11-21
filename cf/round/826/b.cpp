#include <iostream>
using namespace std;

void solve(void) {
    int n;
    cin >> n;

    if (n == 3) {
        cout << "-1\n";
        return;
    }

    for (int i = n; i > (n >> 1) + (n & 1); --i)
        cout << i << ' ';
    
    for (int i = 1; i <= (n >> 1) + (n & 1); ++i)
        cout << i << ' ';
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