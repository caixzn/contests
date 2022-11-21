#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    int ans = 0x7fffffff;
    int fives = 0;
    while (m > 1) {
        if (!(m & 1))
            ans = min(ans, (m >> 1) + fives);
        m -= 5, ++fives;
    }
    if (m == 0) {
        ans = min(ans, fives);
    }
    if (ans == 0x7fffffff)
        cout << "-1\n";
    else
        cout << ans << '\n';
    return 0;
}