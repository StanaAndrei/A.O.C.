#include <bits/stdc++.h>
using namespace std;
constexpr int STEPS = 10;
string polyTemp;
unordered_map<string, string> mp;
map<char, int> fr;

void read() {
    getline(cin, polyTemp);
    for (string a, b; cin >> a;) {
        cin >> b/*ignore ->*/ >> b;
        mp[a] = b;
    }
}

void step() {
    string aux;
    for (size_t i = 0; i < polyTemp.size() - 1; i++) {
        const string ss = polyTemp.substr(i, 2);
        aux += polyTemp[i] + mp[ss];
    }
    aux += polyTemp.back();
    polyTemp = aux;
}

signed main() {
    freopen("text.in", "r", stdin);
    read();
    for (int i = 0; i < STEPS; i++) {
        step();
    }

    for (const char &ch : polyTemp) {
        fr[ch]++;
    }
    int mini = std::min_element(begin(fr), end(fr), [](const auto& l, const auto& r)->bool {
        return l.second < r.second;
    })->second;
    int maxi = std::min_element(begin(fr), end(fr), [](const auto& l, const auto& r)->bool {
        return l.second > r.second;
    })->second;
    cout << maxi - mini << endl;//*/
    return 0;
}
