#include <iostream>
using namespace std;

void solve(void) {
    int n, k;
    cin >> n >> k;
    
    int parts[101] = {0};
    bool possible = true;
    for (int i = 1, num; i <= n; ++i) {
        cin >> num;
        ++parts[num];
        if (parts[num] > 2)
            possible = false;
    }

    if (n > (k << 1))
        possible = false;

    cout << (possible ? "YES\n" : "NO\n");
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}