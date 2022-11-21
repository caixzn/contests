#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> coins(101);
    for (int i = 0, val; i < m; ++i) {
        cin >> val;
        ++coins[val];
    }
    int ans = 0, ans_idx = 0;
    for (int i = 1; i <= 100; ++i) {
        if (i*coins[i] >= ans) {
            ans = i*coins[i];
            ans_idx = i;
        }
    }
    cout << ans << ' ' << ans_idx << '\n';
    return 0;
}