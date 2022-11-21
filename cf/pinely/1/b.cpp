#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

void solve(void) {
    int n;
    cin >> n;
    list<int> l;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        l.push_back(x);
    }
    
    int idx = 0;
    auto circular_next = [&](list<int> &l, list<int>::iterator &it) -> list<int>::iterator {
        return next(it) == l.end() ? l.begin() : next(it);
    };
    auto it = l.begin();
    while (true) {
        cout << *it << ' ';
        it = circular_next(l, it);
        ++idx;
        if (idx >= (n << 1)) break;
    }
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
