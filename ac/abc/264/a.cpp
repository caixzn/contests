#include <iostream>
using namespace std;

int main(void) {
    int l, r;
    cin >> l >> r;
    const string s = "atcoder";
    cout << s.substr(l - 1, r - l + 1) << '\n';
    return 0;
}