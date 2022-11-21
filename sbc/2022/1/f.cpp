#include <iostream>
#include <map>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, c;
    cin >> n >> c;

    map<string, int> table;

    string word;
    for (int i = 0; i < n; ++i) {
        cin >> word;
        int asterisk = 0;
        while (word[asterisk] != '*')
            ++asterisk;
        for (int ch = 'a'; ch <= 'z'; ++ch) {
            word[asterisk] = ch;
            ++table[word];
        }
    }

    int max = -1;
    string ans;
    for (const auto &[k, v] : table) {
        if (v > max) {
            max = v;
            ans = k;
        }
    }

    cout << ans << ' ' << max << '\n';
    return 0;
}