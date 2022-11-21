#include <iostream>
#include <vector>
using namespace std;

void solve(void) {
    int n;
    cin >> n;
    string covered;
    cin >> covered;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    
    for (int i = 1; i < n; ++i) {
        if (covered[i-1] == '0' && covered[i] == '1' && a[i-1] >= a[i])
            swap(covered[i-1], covered[i]);
        else if (covered[i-1] == '0' && covered[i] == '1') {
            int j = i - 1;
            int min = 1 << 30;
            int k = i;
            while (i < n && covered[i] == '1') {
                if (a[i] < min) {
                    min = a[i];
                    k = i;
                }
                ++i;
            }
            if (a[j] >= a[k])
                swap(covered[k], covered[j]);
            i = k;
        }
    }
    
    int64_t sum = 0;
    for (int i = 0; i < n; ++i)
        if (covered[i] == '1')
            sum += a[i];

    cout << sum << '\n';
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