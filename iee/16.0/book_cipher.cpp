#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int p, n, r, c;
    cin >> p >> n >> r;
    cin.ignore();
    cin >> c;
    char pos_code;
    cin >> pos_code;
    vector<string> phrases(p);
    vector<pair<int, int>> letters(128);
    for (int i = 0; i < p; ++i)
        getline(cin >> ws, phrases[i]);

    string input;
    input.reserve(1302);
    for (int i = 0, row = 1, column = 1; i < n; ++i) {
        getline(cin >> ws, input);
        bool ignore = false;
        for (const auto &chr : input) {
            if (chr == '\n' || row > r) break;
            if (ignore && chr == '>') {
                ignore = false;
                continue;
            }
            if (chr == '<') {
                ignore = true;
                continue;
            }
            if (ignore) continue;
            if (letters[chr].first == 0 || pos_code == 'L')
                letters[chr] = {row, column};
            ++column;
            if (column > c) {
                ++row;
                column = 1;
            }
        }
    }

    string ans;
    ans.reserve(5000);
    for (const auto &phrase : phrases) {
        ans.clear();
        for (const auto &chr : phrase) {
            if (letters[chr].first == 0) {
                ans = "0\n";
                break;
            }
            const auto &[x, y] = letters[chr];
            ans += to_string(x);
            ans += ',';
            ans += to_string(y);
            ans += ',';
        }
        ans.back() = '\n';
        cout << ans;
    }

    return 0;
}