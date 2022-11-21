#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
constexpr long long MOD = 1000000007;

long long combine(int n, int end) {
    long long r = 1;
    for (int i = max(n - end, 2); i <= n; ++i) {
        r *= i;
        r %= MOD;
    }
    return r;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> alphabet(26);
    int n, m;
    cin >> n >> m >> ws;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c = cin.get();
            ++alphabet[c-'a'];
        }
        cin >> ws;
    }
    int p;
    cin >> p;
    string word;
    word.reserve(501);
    while (p--) {
        cin >> word;
        sort(word.begin(), word.end());
        long long ans = 0;
        for (size_t i = 0; i < word.size(); ++i) {
            int count = 1;
            while (word[i] == word[i+1]) {
                ++count;
                ++i;
            }
            if (alphabet[word[i]-'a'] >= count) {
                if (ans == 0) ++ans;
                ans *= combine(alphabet[word[i]-'a'], count - 1);
                ans %= MOD;
            } else {
                ans = 0;
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}