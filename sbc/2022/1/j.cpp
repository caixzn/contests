#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    int deck[11] = {0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 16};
    int mary = 0, john = 0;
    int num;
    for (int i = 0; i < 2; ++i) {
        cin >> num;
        num = min(10, num);
        john += num;
        --deck[num];
    }
    for (int i = 0; i < 2; ++i) {
        cin >> num;
        num = min(10, num);
        mary += num;
        --deck[num];
    }

    for (int i = 0; i < n; ++i) {
        cin >> num;
        num = min(10, num);
        mary += num, john += num;
        --deck[num];
    }

    int mary_win = -1;
    if (23 - mary < 11 && deck[23-mary] > 0)
        mary_win = 23 - mary;

    int john_lose = -1;
    if (john > mary && john > 13) {
        for (int i = 24 - john; i <= 10; ++i) {
            if (deck[i] > 0 && mary + i < 24) {
                john_lose = i;
                break;
            }
        }
    }

    if (john_lose > 0)
        cout << john_lose;
    else
        cout << mary_win;
    cout << '\n';

    return 0;
}