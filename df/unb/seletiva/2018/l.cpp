#include <iostream>
using namespace std;

int main(void) {
    int res;
    int play = 2;
    int wins = 0;
    int round = 1;
    do {
        cout << play << endl;
        cin >> res;
        wins += res;
        ++round;
        if (round == 100 && round - wins > wins) {
            play = 1;
        }
    } while (res != -1);
    return 0;
}