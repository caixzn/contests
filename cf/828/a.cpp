#include <iostream>
#include <vector>
#include <set>
using namespace std;

void solve(void) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& x : a)
        cin >> x;

    string s;
    cin >> s;

    vector<char> letters(51);
    for (int i = 0; i < n; ++i) {
        if (!letters[a[i]])
            letters[a[i]] = s[i];
        else if (letters[a[i]] != s[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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