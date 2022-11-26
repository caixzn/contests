#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w;
    cin >> h >> w;
    vector<string> s(w);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            char c;
            cin >> c;
            s[j] += c;
        }
    }
    map<string, int> count_s;
    for (const auto &str : s)
        ++count_s[str];
    vector<string> t(w);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            char c;
            cin >> c;
            t[j] += c;
        }
    }
    map<string, int> count_t;
    for (const auto &str : t)
        ++count_t[str];
    
    bool ok = true;
    for (const auto &kv : count_s) {
        string k = kv.first;
        int v = kv.second;
        if (count_t[k] != v) {
            ok = false;
            break;
        }
    }

    cout << (ok ? "Yes\n" : "No\n");
    return 0;
}
