#include <iostream>
#include <vector>
using namespace std;

void log_chopping(void) {
    int n;
    cin >> n;
    vector<int> logs(n);
    int sum = 0;
    for (auto& log : logs) {
        cin >> log;
        sum += log - 1;
    }
    cout << ((sum & 1) ? "errorgorn\n" : "maomao90\n");
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        log_chopping();
    return 0;
}