#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <vector>
#include <codecvt>
#include <locale>
#include <algorithm>
#include <queue>
using namespace std;

struct node {
    int parent, l, r;
    char32_t c = 0;
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    wstring_convert<codecvt_utf8<char32_t>, char32_t> convert;
    int n, p;
    cin >> n >> p;
    unordered_map<int, node> graph(n << 1);
    map<int, string> langs;
    for (int i = 0; i < n; ++i) {
        char node_type;
        int id, id_l, id_r;
        string str;
        u32string unicode;
        cin >> node_type;
        if (node_type == 'L') {
            cin >> id >> str;
            langs[id] = str;
            graph[id].l = -1;
            graph[id].r = -1;
            continue;
        }
        cin >> id >> str >> id_l >> id_r;
        unicode = convert.from_bytes(str);
        graph[id].c = unicode[0];
        graph[id].l = id_l;
        graph[id].r = id_r;
        graph[id_l].parent = id;
        graph[id_r].parent = id;
    }
    const auto it = graph.begin();
    int root = it->first;
    while (graph[root].parent != 0)
        root = graph[root].parent;
    for (int i = 0; i < p; ++i) {
        string phrase;
        getline(cin >> ws, phrase);
        u32string unicode_p = convert.from_bytes(phrase);
        set<char32_t> u32_chars (unicode_p.begin(), unicode_p.end());
        
        vector<string> ans;
        
        queue<int> search;
        search.push(root);
        while (!search.empty()) {
            if (graph[search.front()].l == -1) {
                ans.push_back(langs[search.front()]);
                search.pop();
                continue;
            }
            if (u32_chars.find(graph[search.front()].c) == u32_chars.end()) {
                search.push(graph[search.front()].r);
            }
            search.push(graph[search.front()].l);
            search.pop();
        }

        sort(ans.begin(), ans.end());
        for (const auto &l : ans) {
            cout << l << ' ';
        }
        cout << '\n';

    }

    return 0;
}