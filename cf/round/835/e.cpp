#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(void) {
    int n;
    cin >> n;
    vector<int> a(n);
    int first_zero = -1;
    int last_one = -1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0 && first_zero == -1)
            first_zero = i;
        else if (a[i] == 1)
            last_one = i;
    }
    
    if (first_zero == -1)
        a[n-1] = 0;
    else if (last_one == -1) {
        a[0] = 1;
    }
    vector<int> zero_qty(n);
    zero_qty[0] = (a[0] == 0);
    for (int i = 1; i < n; ++i) {
        zero_qty[i] += zero_qty[i-1];
        zero_qty[i] += (a[i] == 0);
    }
    int inversions_pre_op = 0;
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i]) {
            inversions_pre_op += zero_qty[n-1] - zero_qty[i];
        }
    }

    if (first_zero == -1 || last_one == -1) {
        cout << inversions_pre_op << '\n';
        return;
    }

    a[first_zero] = 1;
    zero_qty.clear();
    zero_qty.resize(n);
    zero_qty[0] = (a[0] == 0);
    for (int i = 1; i < n; ++i) {
        zero_qty[i] += zero_qty[i-1];
        zero_qty[i] += (a[i] == 0);
    }
    int inversions_post_zero_op = 0;
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i]) {
            inversions_post_zero_op += zero_qty[n-1] - zero_qty[i];
        }
    }
    a[first_zero] = 0;
    a[last_one] = 0;
    zero_qty.clear();
    zero_qty.resize(n);
    zero_qty[0] = (a[0] == 0);
    for (int i = 1; i < n; ++i) {
        zero_qty[i] += zero_qty[i-1];
        zero_qty[i] += (a[i] == 0);
    }
    int inversions_post_one_op = 0;
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i]) {
            inversions_post_one_op += zero_qty[n-1] - zero_qty[i];
        }
    }
    cout << max({inversions_pre_op, inversions_post_zero_op, inversions_post_one_op}) << '\n';
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
