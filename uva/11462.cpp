#include <iostream>
#include <vector>
using namespace std;

void solve(int n) {
    vector<int> people(101);
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        ++people[num];
    }

    bool first = true;
    for (int i = 1; i <= 100; ++i) {
        for (int j = 0; j < people[i]; ++j) {
            if (first) {
                cout << i;
                first = false;
                continue;
            }
            cout << ' ' << i;
        }
    }
    cout << "\n";
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n && n != 0)
        solve(n);
    return 0;
}