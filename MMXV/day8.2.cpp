#include <bits/stdc++.h>
using namespace std;

int solveLine(const string &line) {
    const int len = line.length();
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        if (line[i] == '\"') {
            if (i == 0 || i == len - 1) {
                cnt += 2;
            } else {
                cnt++;
            }
        } else if (line[i] == '\\') {
            cnt++;
        }
    }
    return cnt;
}

signed main() {
    freopen("data.txt", "r ", stdin);
    string line;
    int cnt = 0;
    while (getline(cin, line)) {
        cnt += solveLine(line);
    }

    cout << cnt << endl;
    return 0;
}
