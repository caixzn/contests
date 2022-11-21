#include <iostream>
#include <unordered_map>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    int ans = 0;
    unordered_map<int, int> balloons(n);
    for (int i = 0, h; i < n; ++i) {
        cin >> h;
        if (balloons[h+1] > 0)
            --balloons[h+1];
        else
            ++ans;

        ++balloons[h];
    }

    cout << ans << '\n';
    return 0;
}