#include <bits/stdc++.h>
using namespace std;

signed main() {
    freopen("data.txt", "r ", stdin);
    uint64_t sum = 0;
    char ch;//to skip ' '
    array<int, 3> arr;
    while (cin >> arr[0]) {
        cin >> ch >> arr[1] >> ch >> arr[2];
        sum += accumulate(arr.cbegin(), arr.cend(), 1ULL, multiplies<decltype(arr)::value_type>());

        auto fiMinIt = min_element(arr.begin(), arr.end());
        int fiMin = *fiMinIt;
        *fiMinIt = numeric_limits<decltype(arr)::value_type>::max();
        auto seMinIt = min_element(arr.begin(), arr.end());

        sum += 1ULL * ((fiMin << 1) + (*seMinIt << 1));
    }
    cout << sum << endl;
    return 0;
}
