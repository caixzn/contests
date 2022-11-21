#include <iostream>
using namespace std;

void solve(void) {
    string a, b;
    cin >> a >> b;

    if (a == b) {
        cout << "=\n";
        return;
    }
    if ((a.back() == 'S' && b.back() != 'S') || (b.back() == 'L' && a.back() != 'L')) {
        cout << "<\n";
        return;
    }
    if ((b.back() == 'S' && a.back() != 'S') || (a.back() == 'L' && b.back() != 'L')) {
        cout << ">\n";
        return;
    }

    int a_x_count = 0;
    for (const auto &c : a)
        if (c == 'X')
            ++a_x_count;
    if (a.back() == 'S')
        a_x_count = -a_x_count;

    int b_x_count = 0;
    for (const auto &c : b)
        if (c == 'X')
            ++b_x_count;
    if (b.back() == 'S')
        b_x_count = -b_x_count;

    cout << (a_x_count > b_x_count ? '>' : '<') << '\n';
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}