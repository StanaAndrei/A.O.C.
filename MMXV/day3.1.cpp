#include <bits/stdc++.h>
using namespace std;

signed main() {
    freopen("data.txt", "r ", stdin);
    string s;
    getline(cin, s);
    int x = 0, y = 0;
    set<pair<int, int>> uset{
        make_pair(x, y)
    };
    for (char ch : s) {
        switch (ch) {
            case '^': y++; break;
            case 'v': y--; break;
            case '>': x++; break;
            case '<': x--; break;
            default: assert(false);
        }
        uset.emplace(x, y);
    }
    cout << uset.size() << endl;
    return 0;
}
