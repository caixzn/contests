#include <iostream>
#include <vector>
using namespace std;

void solve(void) {
    int n;
    cin >> n;
    vector<bool> a(n);
    vector<bool> b(n);
    for (int i = 0; i < n; ++i) {
        char bin;
        cin >> bin;
        a[i] = bin-'0';
    }
    for (int i = 0; i < n; ++i) {
        char bin;
        cin >> bin;
        b[i] = bin - '0';
    }
    vector<bool> aux(a);
    aux.flip();
    if (a != b && aux != b) {
        cout << "no\n";
        return;
    }
    cout << "yes\n";
    int lz = 0, ones = 0, tz = 0;
    bool flip = a[0] == b[0];
    if (flip) {
        for (int i = 0; i < n; ++i) {
            ;
        }
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