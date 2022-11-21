#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, c;
    cin >> n >> c;

    int teams[5] = {0};
    for (int i = 0, t; i < n; ++i) {
        cin >> t;
        ++teams[t];
    }

    int ans = teams[3] + teams[4];
    int extra_players = teams[1] + teams[4];
    if (extra_players < teams[2]) {
        ans += extra_players;
    } else {
        ans += teams[2];
        extra_players -= teams[2];
        ans += extra_players/3;
    }

    if (ans*3 > c) {
        ans = c/3;
    }

    cout << ans << '\n';
    return 0;
}
