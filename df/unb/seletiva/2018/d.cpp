#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int words = -1;
    string s;
    do {
        cin >> s;
        ++words;
    } while (s != "#");
    while (words > n) {
        words -= n;
    }
    cout << words << '\n';
    return 0;
}