#include <bits/stdc++.h>
using namespace std;
//#define PART_ONE

vector<int> getInputAsInts() {
    string s;
    vector<int> inputAsInts;
    while (getline(cin, s, ',')) {
        inputAsInts.push_back(stoi(s));
    }
    return inputAsInts;
}

int64_t computeProg(int x) {
#ifdef PART_ONE
    return x;
#endif
    return 1LL * x * (x + 1) / 2;
}

signed main() {
    freopen("text.in", "r", stdin);
    const auto arr = getInputAsInts();
    const int &maxi = *max_element(begin(arr), end(arr));
    const int &mini = *min_element(begin(arr), end(arr));
    int64_t ans = LLONG_MAX;
    for (int pos = mini; pos < maxi; pos++) {
        int64_t currAns = 0;
        for (const int &it : arr) {
            currAns += computeProg(abs(it - pos));
        }
        if (currAns) {
            ans = min(ans, currAns);
        }
    }
    cout << ans << endl;
    return 0;
}
