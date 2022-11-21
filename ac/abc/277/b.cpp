#include <iostream>
#include <set>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    set<string> strings;
    set<char> first_chars;
    set<char> second_chars;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        strings.insert(s);
        first_chars.insert(s[0]);
        second_chars.insert(s[1]);
    }

    if (strings.size() != n) {
        cout << "No\n";
    } else {
        bool ok = true;
        for (const auto &val : first_chars) {
            if (val != 'H' && val != 'D' && val != 'C' && val != 'S') {
                ok = false;
                break;
            }
        }
        if (ok) {
            for (const auto &val : second_chars) {
                if (val != 'A' && (val < '2' || val > '9') && val != 'T' && val != 'J' && val != 'Q' && val != 'K') {
                    ok = false;
                    break;
                }
            }
        }
        cout << (ok ? "Yes\n" : "No\n");
    }
    return 0;
}
