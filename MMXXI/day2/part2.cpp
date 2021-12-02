#include <bits/stdc++.h>
using namespace std;

signed main() {
    freopen("text.in", "r", stdin);
    int depth = 0, horiz = 0, aim = 0;
    for (string s; cin >> s;) {
        int x;
        cin >> x;
        if (s == "forward") {
            horiz += x;
            depth += aim * x;
        } else if (s == "up") {
            aim -= x;
        } else {
            aim += x;
        }
    }
    cout << 1ULL * depth * horiz << endl;
    return 0;
}
