#include <iostream>
#include <deque>
using namespace std;

void candies(void) {
    int n;
    cin >> n;
    deque<int> candy;
    for (int i = 0, wt; i < n; ++i) {
        cin >> wt;
        candy.push_back(wt);
    }
    if (n < 2) {
        cout << "0\n";
        return;
    }
    int64_t alice = candy[0], bob = candy[n - 1], ans = alice == bob;
    for (int i = 0, j = n - 1; j > i;) {
        if (alice < bob) {
            int64_t alice_tmp = alice;
            for (int k = i + 1; alice_tmp < bob; ++k) {
                alice_tmp += candy[k];
            }
        }
    }
}

int main(void) {
    int t;
    cin >> t;
    while (t--)
        candies();
    return 0;
}