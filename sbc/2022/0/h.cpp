#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull soma(ull num) {
    if (num == 0)
        return 0;
    else {
        ull an = 5 + (num - 1)*3;
        return ((5 + an)*num)/2;
    }
}

ull pa(ull num) {
    return 2 + soma(num-1);  
}

ull busca_binaria(ull num) {
    ull left = 0, right = (ull) 1e9;
    ull mid = (left&right) + ((left^right) >> 1);
    while (left < right) {
        if (pa(mid) > num)
            right = mid - 1;
        else if (pa(mid) < num && left != mid)
            left = mid;
        else if (pa(mid + 1) > num)
            return mid;
        else
            left = mid + 1;

        mid = (left&right) + ((left^right) >> 1);
    }

    return mid;
}

void control(void) {
    int t;
    cin >> t;
    ull num;
    while (t--) {
        cin >> num;
        cout << busca_binaria(num) << '\n';
    }
    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    control();
    return 0;
}
