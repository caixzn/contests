#include <iostream>
#include <set>
using namespace std;

void solve(void) {
    int n;
    cin >> n;
    set<int> angles;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        x = (x%360 + 360)%360;
        angles.insert(x);
        angles.insert((x+180)%360);
    }
    if (n == 0) {
        cout << "1\n";
        return;
    }
    cout << angles.size() << '\n';
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