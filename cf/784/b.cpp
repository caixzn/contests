#include <iostream>
#include <unordered_map>
using namespace std;

void three_times(void) {
    int n, num, ans = -1;
    cin >> n;
    unordered_map<int, int> count(n);
    while (n--) {
        cin >> num;
        ++count[num];
        if (count[num] > 2)
            ans = num;
    }
    cout << ans << '\n';
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        three_times();
    return 0;
}