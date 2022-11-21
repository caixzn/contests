#include <iostream>
#include <vector>
using namespace std;

bool bfs(vector<vector<char>> &grid, int x, int y) {
    
}

    int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w;
    cin >> h >> w;
    vector<vector<char>> grid(h, vector<char>(w));
    int start_x, start_y;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                start_x = i;
                start_y = j;
            }
        }
    }

    bool ok = bfs(grid, start_x, start_y);
    cout << (ok ? "Yes" : "No") << '\n';
    return 0;
}