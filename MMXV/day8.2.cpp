#include <bits/stdc++.h>
using namespace std;

signed main() {
    freopen("data.txt", "r ", stdin);
    string s;
    int lenLiteral = 0, lenInMem = 0;
    while (getline(cin, s)) {
        int len = s.length();
        lenLiteral += len;

        int currLenInMem = len - 2;
        for (int i = 1; i < len - 1; i++) {
            if (s[i] == '\\') {
                if (s[i + 1] == 'x') {
                    currLenInMem -= 3;
                    i += 3;
                } else {
                    currLenInMem--;
                    i++;
                }
            }
        }
        lenInMem += currLenInMem;
    }

    cout << lenLiteral - lenInMem << endl;
    return 0;
}
