#include <iostream>
#include <list>
#include <map>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    map<int, list<int>> m;
    vector<int> balloons(n);

    for (int i = 0; i < n; ++i) {
        cin >> balloons[i];
        m[balloons[i]].push_back(i);
    }

    int arrows = n;

    for (int i = 0; i < n; ++i) {
        int aux = balloons[i] - 1;
        int aux_idx = i;
        while (!m[aux].empty() && m[aux].front() > aux_idx) {
            m[aux].pop_front();
            --aux;
            --arrows;
            aux_idx = m[aux].front();
	    }

        if (m[balloons[i]].front() == i)
            m[balloons[i]].pop_front();
    }

    cout << arrows << '\n';
}