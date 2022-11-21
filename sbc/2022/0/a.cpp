#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(2);

    int n;
    cin >> n;
    string name;
    vector<double> notas;
    double nota;
    while (n--) {
        getline(cin >> ws, name);
        notas.clear();
        do {
            cin >> nota;
            notas.push_back(nota);
        } while (cin.get() != '\n');
        sort(notas.rbegin(), notas.rend());

        double total = 0;
        for (int i = 0; i < min(3, (int)notas.size()); ++i)
            total += notas[i];
        cout << name << ": " << total/(double)min(max((int)notas.size(), 2), 3) << '\n';
    }
    return 0;
}
