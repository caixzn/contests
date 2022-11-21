#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    int idx = 1;
    for (int i = 0; i < n; ++i, ++idx) {
        int p;
        cin >> p;
        if (p == k)
            cout << idx << '\n';
    }
    return 0;
}
