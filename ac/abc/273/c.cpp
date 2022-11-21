#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    map<int, int> count;
    set<int> s;
    for (int i = 0, ai; i < n; ++i) {
        cin >> ai;
        s.insert(ai);
        ++count[ai];
    }

    vector<int> numbers;
    for (const auto &x : s)
        numbers.push_back(x);

    int sz = (int)numbers.size();
    for (int i = 0; i < n; ++i) {
        if (i >= sz) {
            cout << 0 << '\n';
        } else {
            cout << count[numbers[sz - 1 - i]] << '\n';
        }
    }

    return 0;
}