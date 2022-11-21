#include <iostream>
using namespace std;

int gcd(int a, int b) {
    return a == 0 ? b : gcd(b%a, a);
}

void solve(void) {
    int n;
    cin >> n;

    int a[1001] = {0};
    for (int i = 1, num; i <= n; ++i) {
        cin >> num;
        a[num] = i;
    }

    int ans = -1;
    for (int i = 1; i <= 1000; ++i)
        for (int j = i; j <= 1000; ++j)
            if (a[i] > 0 && a[j] > 0 && gcd(i, j) == 1)
                ans = max(ans, a[i] + a[j]);

    cout << ans << '\n';
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