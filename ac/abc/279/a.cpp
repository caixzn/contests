#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int ans = 0;
    for (const auto &ch : s) {
        if (ch == 'v') ++ans;
        else ans += 2;
    }
    cout << ans << '\n';
    return 0;
}
