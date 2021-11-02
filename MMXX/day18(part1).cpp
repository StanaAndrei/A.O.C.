#include <bits/stdc++.h>
using namespace std;
unsigned it;
string s;

int64_t eval() {

    int64_t r = 0;
    char op = '+';
    while (it < s.size() && s[it] != ')') {
        if (strchr("+*", s[it])) {
            op = s[it];
            it++;
            continue;
        }
        if (s[it] == ' ') {
            it++;
            continue;
        }
        int64_t nr = 0;
        bool dig = false;
        while (isdigit(s[it])) {
            nr = nr * 10 + s[it] - '0';
            it++;
            dig = true;
        }
        if (s[it] == '(') {
            it++;
            dig = true;
            nr = eval();
            it++;
        }
        if (!dig)
            continue;
        if (op == '+')
            r += nr;
        else
            r *= nr;
    }
    return r;
}

int main()
{
    freopen("text.in", "r", stdin);
    int64_t r = 0;
    while (getline(cin, s)) {
        it = 0;
        r += 1LL * eval();
    }
    cout << r << endl;
    return 0;
}
