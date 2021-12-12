#include <bits/stdc++.h>
using namespace std;
map<string, set<string>> edges;

void mkGraph() {
    for (string line; getline(cin, line);) {
        stringstream ss(line);
        string a, b;
        for (string s; getline(ss, s, '-');) {
            if (a.empty()) {
                a = s;
            } else {
                b = s;
            }
        }
        edges[a].insert(b);
        edges[b].insert(a);
    }
}

int dfs(string s, set<string> trav) {
    if (s == "end") {
        return 1;
    }
    if (islower(s[0])) {
        if (trav.count(s)) {
            trav.insert("*");
        } else {
            trav.insert(s);
        }
    }
    int r = 0;
    for (const auto &nxt : edges[s]) {
        if (!(nxt == "start" || (trav.count(nxt) && trav.count("*")))) {
            r += dfs(nxt, trav);
        }
    }
    return r;
}

signed main() {
    freopen("text.in", "r", stdin);
    mkGraph();
    const int ans = dfs("start", {});
    cout << ans << endl;
    return 0;
}
