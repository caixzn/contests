#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &ai : a)
        cin >> ai;
    prev_permutation(a.begin(), a.end());
    for (const auto &ai : a) {
        cout << ai << ' ';
    }
    cout << '\n';
    return 0;
}