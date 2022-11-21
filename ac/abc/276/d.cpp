#include <iostream>
#include <vector>
#include <set>
using namespace std;

// vector<int> fact(long long n) {
//     vector<int> div;
//     for (long long i = 2; i * i <= n; i++) {
//         if (n % i == 0) {
//             div.push_back(i);
//             if (n/i != i)
//                 div.push_back(n/i);
//         }
//     }
//     if (n != 1)
//         div.push_back(n);
//     return div;
// }

vector<int> fact_no_2_or_3(long long n) {
    vector<int> div;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            bool ok = i != 3 && i != 2;
            while (n % i == 0) {
                n /= i;
                if (ok)
                    div.push_back(i);
            }
        }
    }
    if (div.empty() && n != 3 && n != 2 && n != 1)
        div.push_back(n);
    return div;
}

pair<int, int> fact_only_2_or_3(long long n) {
    pair<int, int> count;
    for (long long i = 2; i <= 3; i++) {
        if (n % i == 0) {
            bool ok = i == 3 || i == 2;
            while (n % i == 0) {
                n /= i;
                if (i == 2)
                    ++count.first;
                else ++count.second;
            }
        }
    }
    return count;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &ai : a) {
        cin >> ai;
    }
    auto v = fact_only_2_or_3(a[0]);
    vector<pair<int, int>> fact_2_3(n);
    set<vector<int>> common_factors;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        fact_2_3[i] = fact_only_2_or_3(a[i]);
        common_factors.insert(fact_no_2_or_3(a[i]));
        if (common_factors.size() > 1) {
            ans = -1;
            break;
        }
    }
    if (ans == 0) {
        int min_two = 0x7fffffff, min_three = 0x7fffffff;
        for (const auto &[two, three] : fact_2_3) {
            if (two < min_two)
                min_two = two;
            if (three < min_three)
                min_three = three;
        }

        ans -= min_two*n;
        ans -= min_three*n;
        for (const auto &[two, three] : fact_2_3) {
            ans += two;
            ans += three;
        }
    }
    cout << ans << '\n';
    return 0;
}