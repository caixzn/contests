#include <iostream>
using namespace std;

constexpr int KEY = 14;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    getline(cin, s);
    for (auto &c : s) {
        if (c >= 'A' && c <= 'Z') {
            c = (int(c) + KEY - 'A')%26 + 'A';
        } else if (c >= 'a' && c <= 'z') {
            c = (int(c) + KEY - 'a') % 26 + 'a';
        }
    }
    cout << s;
    return 0;
}