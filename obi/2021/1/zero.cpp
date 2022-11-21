#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0, p = 0; i < n; ++i, ++p) {
        cin >> numbers[p];
        if (!numbers[p])
            --p, numbers[p] = 0, --p;
    }
    int ans = 0;
    for (const auto& num : numbers) {
        if (!num)
            break;
        ans += num;
    }
    cout << ans << '\n';
    return 0;
}