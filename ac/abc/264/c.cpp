#include <iostream>
#include <map>
using namespace std;

int main(void) {
    map<int, int> a;

    int h1, w1;
    cin >> h1 >> w1;
    int num;
    for (int i = 0; i < h1; ++i) {
        for (int j = 0; j < w1; ++j) {
            cin >> num;
            ++a[num];
        }
    }
    
    map<int, int> b;
    int h2, w2;
    cin >> h2 >> w2;
    for (int i = 0; i < h2; ++i) {
        for (int j = 0; j < w2; ++j) {
            cin >> num;
            ++b[num];
        }
    }
    
    bool flag = true;
    for (const auto& i : b) {
        if (a[i.first] < i.second) {
            flag = false;
            break;
        }
    }

    cout << (flag ? "Yes" : "No") << '\n';

    return 0;
}