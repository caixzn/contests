#include <iostream>
#include <algorithm>
using namespace std;

void solve(void) {
    long long n;
    cin >> n;
    string s;
    cin >> s;

    long long count[2] = {0};
    long long max_seq[2] = {0};
    max_seq[s[0]-'0'] = 1;
    count[s[0]-'0'] = 1;
    for (long long i = 1, curr_seq = 1; i < n; ++i) {
        ++count[s[i]-'0'];
        if (s[i-1] == s[i])
            ++curr_seq;
        else {
            curr_seq = 1;
        }
        max_seq[s[i]-'0'] = max(max_seq[s[i]-'0'], curr_seq);
    }
    cout << max({count[0]*count[1], max_seq[0]*max_seq[0], max_seq[1]*max_seq[1]}) << '\n';
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