#include <iostream>
#include <map>
#include <vector>
using namespace std;

void solve(void) {
    int m;
    cin >> m;

    map<string, int> meals;
    string paid;
    int n;
    string ate;
    for (int i = 0; i < m; ++i) {
        cin >> paid >> n;
        meals[paid] += n;
        while (n--) {
            cin >> ate;
            --meals[ate];
        }
    }

    int debt = 0, days = 0;
    for (const auto &[k, v] : meals) {
        if (v >= 0) {
            days = max(days, v);
            continue;
        }
        debt += (-v);
    }
    cout << debt << ' ' << min(debt, days) << '\n';
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