#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string clue;
    cin >> clue;
    string s;
    while (true) {
        getline(cin >> ws, s);
        if (s == "Que horas sao? Sao 5 e 60!")
            break;
        string first_letters = "";
        bool read_char = true;
        for (const auto &c : s) {
            if (read_char) {
                first_letters += c;
                if (c >= 'A' && c <= 'Z')
                    first_letters.back() += 0x20;
                read_char = false;
            } else if (c == ' ') {
                read_char = true;
            }
        }

        size_t to_find = clue.size();
        size_t i = 0;
        for (const auto &c : clue) {
            while (i < first_letters.size() && first_letters[i] != c) ++i;
            if (first_letters[i] != c) break;
            --to_find;
            if (i == first_letters.size() - 1) break;
        }

        cout << '#' << (to_find == 0 ? "lorota" : "tereteteu") << '\n';
    }
    return 0;
}