#include <bits/stdc++.h>
using namespace std;
constexpr int RESET_VAL = 6, AFTER = 256, NEW_FISH_TIME = 8;

vector<int> getInputAsInts() {
    string s;
    vector<int> inputAsInts;
    while (getline(cin, s, ',')) {
        inputAsInts.push_back(stoi(s));
    }
    return inputAsInts;
}

signed main() {
    freopen("text.in", "r", stdin);
    const auto input = getInputAsInts();
    array<int64_t, NEW_FISH_TIME + 1/*max*/> fr = {};
    for (const int &fish : input) {
        fr[fish]++;
    }
    for (int day = 0; day < AFTER; day++) {
        int64_t newOnes = fr[0];
        for (size_t i = 1; i < fr.size(); i++) {
            fr[i - 1] = fr[i];
        }
        fr[NEW_FISH_TIME] = newOnes;
        fr[RESET_VAL] += newOnes;
    }
    cout << accumulate(begin(fr), end(fr), 0LL) << endl;
    return 0;
}
