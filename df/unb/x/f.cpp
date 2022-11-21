#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unsigned long long n;
    cin >> n;

    unsigned long long bricks = ((n*(n + 1)) >> 1)*((n << 1) + 1)/3;

    unsigned long long ans = 0;
    for (unsigned long long i = 1; i*i <= bricks; ++i)
        if (bricks%i == 0) ++ans;

    cout << (ans << 1) << '\n';
    return 0;
}