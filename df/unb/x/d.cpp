#include <iostream>
#include <cstring>
using namespace std;

int max_ans = -1;
char ans[91];
char a[10], b[10], c[10];

bool solve_for_c(char m[91], int num_c) {
    int idx = strlen(c) - 1, digits = 0, num_c_cpy = num_c;
    while (num_c_cpy) num_c_cpy/=10, ++digits;
    while (c[idx] != '\n' && c[idx] != '\0') ++idx;
    if (digits != idx) return false;
    idx -= c[idx] == '\n';
    char m_cpy[91];
    memset(m_cpy, -1, 91*sizeof(char));
    for (int i = 'A'; i < 'Z'; ++i)
        m_cpy[i] = m[i];
    while (idx >= 0) {
        if (m_cpy[c[idx]] == -1)
            m_cpy[c[idx]] = num_c%10;
        else if (m_cpy[c[idx]] != num_c%10 || num_c == 0)
            return false;
        num_c/=10, --idx;
    }
    for (int i = 'A'; i <= 'Z'; ++i)
        ans[i] = m_cpy[i];
    return true;
}

void solve(char m[91], const char *to_define) {
    if (to_define[0] == '\0') {
        int num_a = 0, num_b = 0, num_c = 0;

        for (int i = 0; i < 10; ++i) {
            if (a[i] == '\0' || a[i] == '\n') break;
            num_a = 10*num_a + m[a[i]];
        }
        for (int i = 0; i < 10; ++i) {
            if (b[i] == '\0' || b[i] == '\n') break;
            num_b = 10*num_b + m[b[i]];
        }
        num_c = num_a + num_b;

        if (num_c > max_ans, solve_for_c(m, num_c))
            max_ans = num_c;
        return;
    }
    char ch = to_define[0];
    for (int i = 0; i <= 9; ++i) {
        m[ch] = i;
        if (m[a[0]] == 0 || m[b[0]] == 0 || m[c[0]] == 0)
            continue;
        solve(m, to_define + 1);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    fgets(a, 10, stdin);
    fgets(b, 10, stdin);
    fgets(c, 10, stdin);

    char m[91];
    memset(m, -1, 91*sizeof(char));
    
    for (int i = 0; i < 10; ++i) {
        if (a[i] == '\0' || a[i] == '\n') break;
        m[a[i]] = 1;
    }
    for (int i = 0; i < 10; ++i) {
        if (b[i] == '\0' || b[i] == '\n') break;
        m[b[i]] = 1;
    }

    char to_def[10] = {0};
    for (int i = 'A', idx = 0; i <= 'Z'; ++i)
        if (m[i] == 1)
            to_def[idx++] = i;

    solve(m, to_def);

    printf("%d\n", max_ans);
    if (max_ans == -1)
        return 0;

    for (int i = 'A'; i <= 'Z'; ++i) {
        if (ans[i] != -1)
            printf("%c:%hd\n", i, ans[i]);
    }


    return 0;
}