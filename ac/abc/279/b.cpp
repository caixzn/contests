#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t;
    cin >> s >> t;
    if (s.find(t) == s.npos) cout << "No\n";
    else cout << "Yes\n";
    return 0;
}
