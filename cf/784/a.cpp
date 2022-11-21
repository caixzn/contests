#include <iostream>
using namespace std;

int main(void) {
    int t, rating;
    cin >> t;
    while (t--) {
        cin >> rating;
        cout << "Division ";
        if (rating > 1899)
            cout << "1\n";
        else if (rating > 1599)
            cout << "2\n";
        else if (rating > 1399)
            cout << "3\n";
        else
            cout << "4\n";
    }
}