#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string input;
    priority_queue<int64_t> elves;
    int64_t elf = 0;
    while(getline(cin, input)) {
        if (input.empty()) {
            elves.push(elf);
            elf = 0;
            continue;
        }
        elf += stoll(input);
    }
    elves.push(elf);
    // part 1
    cout << elves.top() << '\n';
    // part 2
    int64_t ans = 0;
    for (int i = 0; i < 3; ++i) {
        if (elves.empty()) break;
        ans += elves.top();
        elves.pop();
    }
    cout << ans << '\n';
    return 0;
}
