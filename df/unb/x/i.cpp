#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, s;
    cin >> n >> s;
    
    unordered_map<int, int> m(n);
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        ++m[h[i]];
    }
    
    for (const auto &hi : h) {
        if (hi - s > 0 && m[hi-s]) {
            if (hi == m[hi-s] && m[hi-s] < 2)
                continue;
            cout << "Sim\n";
            return 0;
        }
    }
    cout << "Nao\n";

    return 0;
}