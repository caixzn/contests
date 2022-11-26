#include <iostream>
#include <vector>
using namespace std;

void solve(void) {
    int n;
    cin >> n;
    int best = -1;
    int best_idx = 0;
    int second = -1;
    int second_idx = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] >= best) {
            second = best;
            second_idx = best_idx;
            best = a[i];
            best_idx = i;
        } else if (a[i] >= second) {
            second = a[i];
            second_idx = i;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i == best_idx) {
            cout << a[i] - second << ' ';
            continue;
        }
        cout << a[i] - best << ' ';
    }
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
