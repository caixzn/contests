#include <iostream>
#include <vector>
using namespace std;

void printcanvas(vector<vector<char>> &canvas) {
    for (const auto &r : canvas) {
        for (const auto &c : r)
            cout << c;
        cout << '\n';
    }
}

bool ckfriends(int i, int j, const int r, const int c, vector<vector<char>> &m) {
    int friends = 0;
    if (i > 0 && m[i-1][j] == '^')
        ++friends;
    if (i + 1 < r && m[i+1][j] == '^')
        ++friends;
    if (j > 0 && m[i][j-1] == '^')
        ++friends;
    if (j + 1 < c && m[i][j+1] == '^')
        ++friends;
    return friends > 1;
}

bool try_add_friends(int i, int j, const int r, const int c, vector<vector<char>> &m) {
    if (i > 0 && m[i-1][j] == '.') {
        m[i-1][j] = '^';
        if (!ckfriends(i - 1, j, r, c, m) && !try_add_friends(i - 1, j, r, c, m))
            m[i-1][j] = '.';
        if (ckfriends(i, j, r, c, m))
            return true;
    }
    if (i + 1 < r && m[i+1][j] == '.') {
        m[i+1][j] = '^';
        if (!ckfriends(i + 1, j, r, c, m) && !try_add_friends(i + 1, j, r, c, m))
            m[i+1][j] = '.';
        if (ckfriends(i, j, r, c, m))
            return true;
    }
    if (j > 0 && m[i][j-1] == '.') {
        m[i][j-1] = '^';
        if (!ckfriends(i, j - 1, r, c, m) && !try_add_friends(i, j - 1, r, c, m))
            m[i][j-1] = '.';
        if (ckfriends(i, j, r, c, m))
            return true;
    }
    if (j + 1 < c && m[i][j+1] == '.') {
        m[i][j+1] = '^';
        if (!ckfriends(i, j + 1, r, c, m) && !try_add_friends(i, j + 1, r, c, m))
            m[i][j+1] = '.';
        if (ckfriends(i, j, r, c, m))
            return true;
    }
    return false;
}

void solve(void) {
    size_t r, c;
    cin >> r >> c;


    vector<vector<char>> canvas(r, vector<char>(c));

    int tree_count = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> canvas[i][j];
            if (canvas[i][j] == '^') {
                ++tree_count;
            }
        }
    }
    if (r*c > 1e5) {
        cout << "Impossible\n";
        return;
    }

    if (tree_count == 0) {
        cout << "Possible\n";
        printcanvas(canvas);
        return;
    }

    bool possible = true;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (canvas[i][j] == '^' && !ckfriends(i, j, r, c, canvas)) {
                possible = try_add_friends(i, j, r, c, canvas);
                if (!possible) {
                    cout << "Impossible\n";
                    return;
                }
            }
        }
    }

    cout << "Possible\n";
    printcanvas(canvas);
    return;
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