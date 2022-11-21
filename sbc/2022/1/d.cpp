#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x, y;
    cin >> n >> x >> y;
    int lsb = 0;
    while (!((1 << lsb) & x)) ++lsb;
    cout << n - 1 - lsb << '\n';
    return 0;
}