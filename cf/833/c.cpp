#include <iostream>
#include <vector>
using namespace std;

void solve(void) {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;

    }
    int ans = 0;

    long long sum = a[0];
    for (int i = 1; i < n; ++i) {
        if (sum == 0) ++ans;
        else if (a[i] == 0) a[i] = -sum;
        sum += a[i];
    }
    if (sum == 0) ++ans;
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
