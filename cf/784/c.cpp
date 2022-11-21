#include <iostream>
#include <vector>
using namespace std;

void odd_even(void) {
    int n;
    cin >> n;
    int odd_idx = 0, even_idx = 0;
    int odd_idx_sum = 0, even_idx_sum = 0;
    for (int i = 0, num; i < n; ++i) {
        cin >> num;
        if (i & 1) {
            ++even_idx;
            even_idx_sum += (num & 1);
        }
        else {
            ++odd_idx;
            odd_idx_sum += (num & 1);
        }
    }
    if (((even_idx == even_idx_sum) || !even_idx_sum) &&
        ((odd_idx == odd_idx_sum) || !odd_idx_sum))
        cout << "yes\n";
    else
        cout << "no\n";
}

int main(void) {
    int t;
    cin >> t;
    while (t--)
        odd_even();
    return 0;
}