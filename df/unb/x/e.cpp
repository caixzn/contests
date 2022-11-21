#include <iostream>
using namespace std;

void solve(void) {
    long long p, i, l;
    cin >> p >> i >> l;
    --i;

    if (i == -1) {
        cout << "0\n";
    } else if ((l >> i) > 0) {
        cout << max(0LL, p - (l >> i)) << '\n';
    } else {
        cout << "Melhor chamar o Selso.\n";
    }
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