#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    stack<char, vector<char>> stck;
    bool monotonous = false;
    for (int i = 1; i < n; ++i) {
        if (!monotonous && s[i] == 'a' && s[i-1] == 'a') {
            monotonous = true;
            stck.push('a');
            stck.push('a');
        } else if (monotonous && s[i] == 'a') {
            stck.push('a');
        } else {
            monotonous = false;
        }
    }

    cout << stck.size() << '\n';
}