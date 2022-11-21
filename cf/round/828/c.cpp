#include <iostream>
using namespace std;

void solve(void) {
    int n;
    char c;
    cin >> n >> c;
    string s;
    cin >> s;
    if (c == 'g') {
        cout << "0\n";
        return;
    }
    for (size_t i = 0; i < s.size(); ++i) {
        if (s.back() == 'g') break;
        s += s[i];
    }

    int max_seq = 0, cur_seq = 0;
    size_t i = 0;
    while (s[i] != c) ++i;
    while (i < s.size()) {
        ++cur_seq;
        ++i;
        if (s[i] == 'g') {
            max_seq = max(max_seq, cur_seq);
            cur_seq = 0;
            while (s[i] != c && i < s.size()) ++i;
        }
    }
    cout << max_seq << '\n';
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