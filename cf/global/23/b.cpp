#include <iostream>
#include <vector>
using namespace std;

void solve(void) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    
    int ans = 0;
    int first_one = n - 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) {
            first_one = i;
            break;
        }
    }
    int last_zero = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == 0) {
            last_zero = i;
            break;
        }
    }

    for (int i = first_one, j = last_zero; i < j;) {
        ++ans;
        swap(a[i], a[j]);
        while (j >= 0 && a[j] != 0) --j;
        while (i < n && a[i] != 1) ++i;
    }

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