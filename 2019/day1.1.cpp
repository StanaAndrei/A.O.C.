#include <bits/stdc++.h>
using namespace std;

int main(void) {
    freopen("data.txt", "r", stdin);
    uint64_t sum = 0;
    for (int x; cin >> x;) {
        sum += x/3 - 2;
    }
    cout << sum << endl;
    return 0;
}
