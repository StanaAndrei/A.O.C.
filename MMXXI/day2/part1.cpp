#include <bits/stdc++.h>
using namespace std;

signed main() {
    freopen("text.in", "r", stdin);
    string s;
    int depth = 0, horiz = 0;
    while (cin >> s) {
        int x;
        cin >> x;
        if (s == "forward") {
            horiz += x;
        } else if (s == "up") {
            depth -= x;
        } else {
            depth += x;
        }
    }
    cout << 1ULL * depth * horiz << endl;
    return 0;
}
