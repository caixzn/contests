#include <iostream>
#include <map>
using namespace std;
 
int max_ans = -1;
map<char, short> ans;
string a, b, c;
 
void solve(map<char, short> &m, string &to_define) {
    if (to_define.empty()) {
        int num_a = 0, num_b = 0, num_c = 0;
        for (const auto& ch : a)
            num_a = 10*num_a + m[ch];
        for (const auto& ch : b)
            num_b = 10*num_b + m[ch];
        for (const auto& ch : c)
            num_c = 10*num_c + m[ch];
        if (num_c > max_ans && num_a + num_b == num_c) {
            ans = m;
            max_ans = num_c;
        }
        return;
    }
    char chr = to_define.back();
    to_define.pop_back();
    for (int i = 0; i <= 9; ++i) {
        m[chr] = i;
        if (i == 0 && (chr == a.front() && a.size() > 1 ||
            chr == b.front() && b.size() > 1 || chr == c.front() && c.size() > 1))
            continue;
        solve(m, to_define);
    }
    to_define += chr;
}
 
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> a >> b >> c;
 
    map<char, short> m;
    for (const auto &c : a)
        m[c];
    for (const auto &c : b)
        m[c];
    for (const auto &c : c)
        m[c];
 
    string to_define = "";
    for (const auto &kv : m)
        to_define += kv.first;
 
    solve(m, to_define);
 
    cout << max_ans << '\n';
    if (max_ans == -1)
        return 0;
 
    for (const auto &kv : ans)
        cout << kv.first << ':' << kv.second << '\n';
 
 
    return 0;
}