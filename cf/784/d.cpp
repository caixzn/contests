#include <iostream>
using namespace std;

void colorful_stamp(void) {
    int n;
    string str;
    cin >> n >> str;
    int b = 0, r = 0;
    bool ans = true;
    for (const auto ch : str) {
        if (ch == 'B')
            ++b;
        else if (ch == 'R')
            ++r;
        else {
            if (!b && !r)
                continue;
            if ((!b && r) || (b && !r)) {
                ans = false;
                break;
            }
            b = 0, r = 0;
        }
    }
    if ((!b && r) || (b && !r))
        ans = false;
    cout << (ans ? "yes\n" : "no\n");
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        colorful_stamp();
    return 0;
}