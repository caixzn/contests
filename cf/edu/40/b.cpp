#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = n;
	for (int i = 1; i <= (n >> 1); ++i) {
		if (s.substr(0, i) == s.substr(i, i))
			ans = n - i + 1;
	}
	cout << ans << '\n';
	return 0;
}
