#include <bits/stdc++.h>
using ll = long long;
using namespace std;
constexpr int WIN_SIZE = 3;

signed main() {
    freopen("text.in", "r", stdin);
    vector<int> depths;
    for (int x; cin >> x;) {
        depths.push_back(x);
    }
    const int n = depths.size();
    int ans = 0;
    int last = 0, curr = 0;
    for (int i = 0; i < WIN_SIZE; i++) {
        last += depths[i];
    }
    for (int i = 1; i <= n - WIN_SIZE; i++) {
        for (int j = i; j < i + WIN_SIZE; j++) {
            curr += depths[j];
        }
        ans += curr > last;
        last = curr;
        curr = 0;
    }
    cout << ans << endl;
    return 0;
}
