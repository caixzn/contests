#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w, r, c;
    cin >> h >> w >> r >> c;
    int tak_r = r, tak_c = c;

    int n;
    cin >> n;
    vector<pair<int, int>> walls(n);
    vector<pair<int, int>> wall_c(n);
    for (int i = 0; i < n; ++i) {
        cin >> walls[i].first >> walls[i].second;
        wall_c[i] = {walls[i].second, walls[i].first};
    }
    sort(walls.begin(), walls.end());
    sort(wall_c.begin(), wall_c.end());
    
    int q;
    cin >> q;
    char dir;
    int len;
    while (q--) {
        cin >> dir >> len;
        switch (dir) {
            case 'L':
                auto it = lower_bound(wall_c.begin(), wall_c.end(), make_pair(c, r));
                auto it_2 = upper_bound()
                break;
            case 'R':
                break;
            case 'U':
                break;
            case 'D':
                break;
            default:
                break;
        }
    }

    return 0;
}