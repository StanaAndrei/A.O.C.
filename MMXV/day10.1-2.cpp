#include <bits/stdc++.h>
using namespace std;
constexpr char start[] = "1321131112";
constexpr bool part1 = false;/*change this to change part*/
constexpr int n = part1 ? 40 : 50;

string lookAndSay(string s) {
    string ans = "";
    regex rgx(R"((\d)\1*)");
    regex_iterator<string::iterator> it(s.begin(), s.end(), rgx), endIt;
    for (; it != endIt; it++) {
        const string &temp = it->str();
        ans += to_string(temp.size()) + temp[0];
    }
    return ans;
}

signed main() {
    string s = start;
    for (int i = 0; i < n; i++) {
        s = lookAndSay(s);
    }
    cout << s.size() << endl;
    return 0;
}
