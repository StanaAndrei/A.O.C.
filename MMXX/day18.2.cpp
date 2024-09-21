#include <bits/stdc++.h>
using namespace std;
string s;
unsigned it;
int64_t evalOrd1(), evalOrd2(), getNr();

int64_t evalOrd2() {
    int64_t r = evalOrd1();
    while (s[it] == '*') {
        it++;
        if (s[it - 1] == '*')
            r *= evalOrd1();
    }
    return r;
}

int64_t evalOrd1() {
    int64_t r = getNr();
    while (s[it] == '+') {
        it++;
        if (s[it - 1] == '+')
            r += getNr();
    }
    return r;
}

int64_t getNr() {
    int64_t r = 0;
    if (s[it] == '(') {
        it++;
        r = evalOrd2();
        it++;
        return r;
    }
    while (isdigit(s[it])) {
        r = r * 10 + s[it] - '0';
        it++;
    }
    return r;
}

int main()
{
    freopen("text.in", "r", stdin);
    int64_t r = 0;
    while (getline(cin, s)) {
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        it = 0;
        r += evalOrd2();
    }
    cout << r << endl;
    return 0;
}
