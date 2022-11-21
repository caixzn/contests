#include <iostream>
using namespace std;

void aaab(void) {
    string str;
    cin >> str;
    if (str.back() == 'A') {
        cout << "no\n";
        return;
    }
    int a = 0;
    for (const auto& ch : str) {
        if (ch == 'A') {
            ++a;
            continue;
        }
        --a;
        if (a < 0) {
            cout << "no\n";
            return;
        }
    }
    cout << "yes\n";
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        aaab();
    return 0;
}