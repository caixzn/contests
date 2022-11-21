#include <iostream>
using namespace std;

struct lap_time {
    int m, s, ms, driver, lap;

    bool operator<(const lap_time& rhs) const {
        if (this->m == rhs.m && this->s == rhs.s)
            return this->ms < rhs.ms;
        if (this->m == rhs.m)
            return this->s < rhs.s;
        return this->m < rhs.m;
    }

    void operator+=(const lap_time& rhs) {
        this->ms += rhs.ms;
        this->s += this->ms/1000 + rhs.s;
        this->ms %= 1000;
        this->m += this->s/60 + rhs.m;
        this->s %= 60;
    }
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    lap_time l1 = {10, 59, 999}, l2 = {0, 0, 1};
    l1 += l2;
    cout << l1.m << ':' << l1.s << ':' << l1.ms;

    return 0;
}