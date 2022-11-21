#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> qty;
    for (auto &val : a) {
        cin >> val;
        ++qty[val];
    }
    int ans;
    bool ok = false;
    for (const auto &val : a) {
        if ((qty[val - k] >= 2) || (qty[val - k] >= 1 && k)) {
            ans = val;
            ok = true;
            break;
        }
    }
    if (ok) {
        cout << "Sim\n";
        int ans_a[2] = {0};
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == ans || a[i] == ans - k) {
                ans_a[count++] = i+1;
                if (count == 2) break;
            }
        }
        if (a[ans_a[1]-1] - a[ans_a[0]-1] == k)
            swap(ans_a[1], ans_a[0]);
        cout << ans_a[0] << ' ' << ans_a[1] << '\n';
    } else {
        cout << "Nao\n";
    }

    return 0;
}