#include <bits/stdc++.h>
using namespace std;

int main(void) {
    freopen("text.in", "r", stdin);
    uint64_t sum = 0;
    for (int x; cin >> x;) {
        while (x >= 9) {
            x = x/3 - 2;
            sum += x;
        }
    }
    cout << sum << endl;
    return 0;
}
