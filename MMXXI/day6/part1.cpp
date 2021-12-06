#include <bits/stdc++.h>
using namespace std;
constexpr int RESET_VAL = 6, AFTER = 150, NEW_FISH_TIME = 8;;

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
    auto arr = getInputAsInts();
    for (int i = 0; i < AFTER; i++) {
        vector<int> added;
        for (int &x : arr) {
            if (!x) {
                x = RESET_VAL + 1;
                added.push_back(NEW_FISH_TIME);
            }
            x--;
        }
        arr.insert(end(arr), begin(added), end(added));
    }
    cout << arr.size() << endl;
    return 0;
}
