#include <iostream>
using namespace std;

int main(void) {
    int r, c;
    cin >> r >> c;

    const int center = 8;
    bool color = false;
    for (int i = 0; i < center; ++i, color = !color)
        if ((r >= center - i && r <= center + i) && (c >= center - i && c <= center + i))
            break;
    cout << (color ? "black" : "white") << '\n';
    return 0;
}