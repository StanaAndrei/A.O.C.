#include <bits/stdc++.h>
using namespace std;
const int n = 36;
string s, mask;
map<uint64_t, uint64_t> mp;

void bitsBktr(string res, int val) {
    int cntX = 0;
    int idToPos[n + 3] = {};
    for (int i = 0; i < n; i++) {
        if (res[i] == 'X')
            idToPos[cntX++] = i;
    }
    const uint64_t finState = 1ULL * (1 << cntX) - 1;
    for (bitset<n> state(0); (state.to_ullong() <= finState); state = state.to_ullong() + 1) {
        for (int i = 0; i < cntX; i++) {
            res[idToPos[i]] = state[i] + '0';
        }
        mp[bitset<n>(string(res.rbegin(), res.rend())).to_ullong()] = val;
    }//*/
}

int main() {
    freopen("text.in", "r", stdin);
    while (cin >> s) {
        if (s == "mask") {
            cin >> s >> s;
            mask = string(s.rbegin(), s.rend());
        } else {
            bitset<n> bs(atoi(s.substr(4).c_str()));
            int val;
            cin >> s >> val;
            string res;
            res.resize(n);
            for (int i = 0; i < n; i++) {
                if (mask[i] == '0')
                    res[i] = bs[i] + '0';
                else
                    res[i] = mask[i];
            }
            bitsBktr(res, val);
        }
    }//*/
    int64_t sum = 0LL;
    for (auto it : mp) {
        sum += it.second;
    }
    cout << sum << endl;
    return 0;
}
