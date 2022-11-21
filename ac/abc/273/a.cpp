#include <iostream>
using namespace std;

unsigned long long f(unsigned long long x) {
    return x == 0 ? 1 : x*f(x-1);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unsigned long long n;
    cin >> n;
    cout << f(n) << '\n';
    return 0;
}