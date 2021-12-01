#include <bits/stdc++.h>
using ll = long long;
using namespace std;

signed main() {
    freopen("text.in", "r", stdin);
    int last, curr, ans = 0;;
    cin >> last;
    while (cin >> curr) {
        if (curr > last) {
            ans++;
        }
        last = curr;
    }
    cout << ans << endl;
    return 0;
}
