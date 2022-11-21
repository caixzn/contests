#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    char c;
    int zeroes = 0, ones = 0;
    for (int i = 0; i < n; ++i) {
        cin >> c;
        if (c == 'z')
            ++zeroes;
        else if (c == 'n')
            ++ones;
    }

    for (int i = 0; i < ones; ++i)
        cout << 1 << ' ';

    for (int i = 0; i < zeroes; ++i)
        cout << 0 << ' ';
    cout << '\n';

    return 0;
}