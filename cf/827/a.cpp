#include <iostream>
using namespace std;

void solve(void) {
    int a, b, c;
    cin >> a >> b >> c;

    bool ans = false;
    if (a + b == c)
        ans = true;
    else if (a + c == b)
        ans = true;
    else if (b + c == a)
        ans = true;
    
    cout << (ans ? "YES\n" : "NO\n");
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