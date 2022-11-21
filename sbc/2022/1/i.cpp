#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    bool success = true;
    int n;
    for (int i = 0; i < 8; ++i) {
        cin >> n;
        if (n == 9)
            success = false;
    }

    cout << (success ? 'S' : 'F') << '\n';
    return 0;
}