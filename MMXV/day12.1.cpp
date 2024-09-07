#include <bits/stdc++.h>
using namespace std;

signed main() {
    freopen("data.txt", "r ", stdin);
    string s;
    getline(cin, s);
    regex nrReg("((-*[0-9])+)");
    auto nrsBegin = sregex_iterator(s.begin(), s.end(), nrReg);
    auto nrsEnd = sregex_iterator();
    cout << "Found " << distance(nrsBegin, nrsEnd) << " numbers." << endl;
    int64_t sum = 0;
    for (auto it = nrsBegin; it != nrsEnd; it++) {
        const smatch match = *it;
        const string matchStr = match.str();
        sum += atoi(matchStr.data());
    }
    cout << "Sum: " << sum << endl;
    return 0;
}
