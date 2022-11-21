#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    map<int, int> not_visited;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0, val; j < a[i]; ++j) {
            cin >> val;
            ++not_visited[val];
        }
    }
    vector<int> ans;
    for (const auto &[k, v] : not_visited)
        if (v == 3)
            ans.push_back(k);
    sort(ans.begin(), ans.end());
    for (const auto &i : ans)
        cout << i << ' ';
    cout << '\n';
    return 0;
}