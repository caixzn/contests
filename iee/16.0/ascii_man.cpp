#include <iostream>
#include <vector>

using namespace std;

void control() {
    int d;
    cin >> d;
    vector<string> p;
    p.push_back(" o ");
    p.push_back("/|\\");
    p.push_back("/ \\");
    bool turned = false;
    while (d--) {
        string s;
        getline(cin >> ws, s);
        if ((!turned && s == "left hand to head") ||
            (turned && s == "right hand to head")) {
            p[1][2] = ' ';
            p[0][2] = ')';
        } else if ((!turned && s == "left hand to hip") ||
                   (turned && s == "right hand to hip")) {
            p[0][2] = ' ';
            p[1][2] = '>';
        } else if ((!turned && s == "left hand to start") ||
                   (turned && s == "right hand to start")) {
            p[0][2] = ' ';
            p[1][2] = '\\';
        } else if ((!turned && s == "left leg in") ||
                   (turned && s == "right leg in")) {
            p[2][2] = '>';
        } else if ((!turned && s == "left leg out") ||
                   (turned && s == "right leg out")) {
            p[2][2] = '\\';
        } else if ((turned && s == "left hand to head") ||
                   (!turned && s == "right hand to head")) {
            p[0][0] = '(';
            p[1][0] = ' ';
        } else if ((turned && s == "left hand to hip") ||
                   (!turned && s == "right hand to hip")) {
            p[0][0] = ' ';
            p[1][0] = '<';
        } else if ((turned && s == "left hand to start") ||
                   (!turned && s == "right hand to start")) {
            p[0][0] = ' ';
            p[1][0] = '/';
        } else if ((turned && s == "left leg in") ||
                   (!turned && s == "right leg in")) {
            p[2][0] = '<';
        } else if ((turned && s == "left leg out") ||
                   (!turned && s == "right leg out")) {
            p[2][0] = '/';
        } else if (s == "turn") {
            turned = !turned;
            vector<string> aux = p;
            if (aux[0][0] == '(') {
                p[0][2] = ')';
                p[1][2] = ' ';
            }
            if (aux[0][2] == ')') {
                p[0][0] = '(';
                p[1][0] = ' ';
            }
            if (aux[1][0] == '<') {
                p[0][2] = ' ';
                p[1][2] = '>';
            }
            if (aux[1][2] == '>') {
                p[0][0] = ' ';
                p[1][0] = '<';
            }
            if (aux[1][0] == '/') {
                p[0][2] = ' ';
                p[1][2] = '\\';
            }
            if (aux[1][2] == '\\') {
                p[0][0] = ' ';
                p[1][0] = '/';
            }
            // dboas -----
            if (aux[2][0] == '/') {
                p[2][2] = '\\';
            } else {
                p[2][2] = '>';
            }
            if (aux[2][2] == '\\') {
                p[2][0] = '/';
            } else {
                p[2][0] = '<';
            }
        } else {
            for (int i = 4; i < (int)s.size(); i++)
                cout << s[i];
            cout << endl;
            continue;
        }
        for (auto &e : p) {
            cout << e << endl;
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        control();
    return 0;
}