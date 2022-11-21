#include <iostream>
#include <vector>
#include <map>
using namespace std;

void solve(void) {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    
    map<int, int> coverage_lr;
    map<int, int> coverage_rl;

    for (int i = 0; i < n; ++i) {
        if (i + b[i] < n) {
            coverage_lr[i] = i + b[i];
            coverage_rl[i + b[i]] = i;
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        if (i - b[i] >= 0) {
            coverage_lr[i-b[i]] = i;
            coverage_rl[i] = i - b[i];
        }
    }

    bool covered = true;
    for (int i = 0; i < n; ++i) {
        if (!(coverage_lr[i])) {
            covered = false;
            break;
        }
        i = coverage_lr[i];
    }

    if (!covered) {
        for (int i = n - 1; i >= 0; --i) {
            if (!coverage_rl[i]) {
                cout << "NO\n";
                return;
            }
            i = coverage_rl[i];
        }
    }

    cout << "YES\n";
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