#include <iostream>
using namespace std;

int combine(const string &a, const string &b) {
    int flipped = 0;
    for (int i = 0; i < int(a.size()) && i < int(b.size()); ++i) {
        if (a[i] == '0' && b[i] == '0')
            break;
        if (a[i] == '1' && b[i] == '1')
            --flipped;
        ++flipped;
    }
    return flipped;
}

void solve(void) {
    int n;
    cin >> n >> ws;
    string number;

    bool first_one = false;
    for (int i = 0; i < n; ++i) {
        char c = cin.get();
        if (!first_one && c == '0')
            continue;
        else if (!first_one && c == '1')
            first_one = true;
        number += c;
    }

    if (number.empty()) {
        cout << "0\n";
        return;
    }

    size_t first_zero = -1;
    int zero_count = 0;
    for (size_t i = 1; i < number.size(); ++i) {
        if (first_zero == -1 && number[i] == '0') {
            first_zero = i;
            ++zero_count;
        } else if (number[i] == '0') {
            ++zero_count;
        }
    }

    if (zero_count <= 1) {
        for (size_t i = 0; i < number.size(); ++i)
            cout << 1;
        cout << '\n';
        return;
    }

    size_t ans = 0;
    int most_flipped = 0;
    for (size_t i = 0; i < first_zero; ++i) {
        const string a = number.substr(first_zero);
        const string b = number.substr(i, number.size() - first_zero);
        int flipped;
        if ((flipped = combine(a, b)) > most_flipped) {
            most_flipped = flipped;
            ans = i;
        }
        if (most_flipped == zero_count) break;
    }

    for (int i = 0; i < first_zero; ++i)
        cout << 1;
    for (size_t i = ans, j = first_zero; j < number.size(); ++i, ++j) {
        if (number[i] == '1' || number[j] == '1')
            cout << 1;
        else
            cout << 0;
    }
    cout << '\n';
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}