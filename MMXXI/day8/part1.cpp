#include <bits/stdc++.h>
using namespace std;
constexpr array<int, 4> TARGETS = {2, 3, 4, 7};

int solveOneLine(stringstream ss) {
    string s;
    while (ss >> s && s != "|");
    int ans = 0;
    while (ss >> s) {
        const int len = s.size();
        if (binary_search(begin(TARGETS), end(TARGETS), len)) {
            ans++;
        }
    }
    return ans;
}

signed main() {
    freopen("text.in", "r", stdin);
    string line;
    int ans = 0;
    while (getline(cin, line)) {
        ans += solveOneLine(stringstream(line));
    }
    cout << ans << endl;
    return 0;
}
