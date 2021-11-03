#include <bits/stdc++.h>
using namespace std;

signed main() {
    freopen("text.txt", "r ", stdin);
    uint64_t sum = 0;
    char ch;
    for (int x, y, z; cin >> x;) {
        cin >> ch >> y >> ch >> z;
        const int side[3] = {
            x * y,
            y * z,
            x * z,
        };
        sum += 2 * (side[0] + side[1] + side[2]) + *min_element(side, side + 3);
    }
    cout << sum << endl;
    return 0;
}
