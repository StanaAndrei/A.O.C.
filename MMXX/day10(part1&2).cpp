#include <bits/stdc++.h>
using namespace std;
int k, v[100], fr[4];
uint64_t dp[100];
//dp[i]-nr of combinations until position i

int main() {
    freopen("text.in", "r", stdin);
    while (cin >> v[++k]);
    k--;
    sort(v + 1, v + k + 1);
    for (int i = 0; i < k; i++) {
        fr[v[i + 1] - v[i]]++;
    }
    fr[3]++;
    cout << fr[1] * fr[3] << endl;
    //part2
    dp[0] = 1;
    for (int i = 1; i <= k; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (v[i] - v[j] > 3)
                break;
            dp[i] += dp[j];
        }
    }
    cout << dp[k] << endl;
    return 0;
}
