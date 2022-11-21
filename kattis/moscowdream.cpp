#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    if (a && b && c && a+b+c >= n && n >= 3)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}