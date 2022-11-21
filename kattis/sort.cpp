#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    int c;
    cin >> c;
    map<int, int> count;
    map<int, int> first;

    int idx = 0;
    for (auto &i : a) {
        cin >> i;
        ++count[i];
        if (first.find(i) == first.end())
            first[i] = idx++;
    }

    sort(a.begin(), a.end(), [&](const int &a, const int &b) {
        if (count[a] == count[b])
            return first[a] < first[b];
        return count[a] > count[b];
    });

    for (const auto &i : a)
        cout << i << ' ';
    cout << '\n';
    return 0;
}