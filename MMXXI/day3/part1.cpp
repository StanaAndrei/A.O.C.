#include <bits/stdc++.h>
using namespace std;

signed main() {
    freopen("text.in", "r", stdin);
    vector<string> vs;
    for (string s; cin >> s;) {
        reverse(begin(s), end(s));
        vs.push_back(s);
    }
    const int n = vs.size();
    const int m = vs[0].size();
    bitset<32> gamma, epsilon;
    for (int col = 0; col < m; col++) {
        int fr[2] = {};
        for (int line = 0; line < n; line++) {
            fr[vs[line][col] - '0']++;
        }
        if (fr[0] > fr[1]) {
            gamma[col] = 0;
            epsilon[col] = 1;
        } else {
            gamma[col] = 1;
            epsilon[col] = 0;
        }
    }
    cout << gamma.to_ullong() * epsilon.to_ullong() << endl;
    return 0;
}
