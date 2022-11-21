#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int64_t x, k;
    cin >> x >> k;

    int64_t x_copy = x;
    for (int i = 0; i < k; ++i) {
        if (x_copy%10 < 5) {
            x -= (x_copy%10)*((int64_t)pow(10, i));
        } else {
            x += (10 - x_copy%10)*((int64_t)pow(10, i));
            x_copy += 10;
        }
        x_copy /= 10;
    }

    cout << x << '\n';
    return 0;
}