#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct stone {
    double dist;
    bool team;

    bool operator<(const stone &rhs) const {
        return this->dist > rhs.dist;
    }
};

void solve(void) {
    int rs, rh;
    cin >> rs >> rh;

    int n;
    cin >> n;
    vector<pair<int, int>> red_stones(n);
    for (int i = 0; i < n; ++i)
        cin >> red_stones[i].first >> red_stones[i].second;
    
    int m;
    cin >> m;
    vector<pair<int, int>> yellow_stones(n);
    for (int i = 0; i < m; ++i)
        cin >> yellow_stones[i].first >> yellow_stones[i].second;

    vector<stone> stones_in_house;
    for (int i = 0; i < n; ++i) {
        double dist = hypot(red_stones[i].first, red_stones[i].second);
        if (rh >= (dist - rs))
            stones_in_house.push_back({dist, 0});
    }
    for (int i = 0; i < m; ++i) {
        double dist = hypot(yellow_stones[i].first, yellow_stones[i].second);
        if (rh >= (dist - rs))
            stones_in_house.push_back({dist, 1});
    }
    sort(stones_in_house.begin(), stones_in_house.end());

    bool winning_team = stones_in_house[0].team;
    int score = 1;
    for (int i = 1; i < (int)stones_in_house.size(); ++i) {
        if (stones_in_house[i].team != winning_team)
            break;
        ++score;
    }
    if (winning_team) {
        cout << 0 << ' ' << score << '\n';
    } else {
        cout << score << ' ' << 0 << '\n';
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}