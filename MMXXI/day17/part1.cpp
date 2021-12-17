#include <bits/stdc++.h>
using namespace std;

struct Area {
    int x[2], y[2];
    bool isInAreaY(const int &cy) {
        return y[0] <= cy && cy <= y[1];

    }
} area;

vector<string> tokenize(string s, const string &sep) {
    vector<string> r;
    char *arr = &s[0];
    for (char *tok = strtok(arr, sep.c_str()); tok; tok = strtok(NULL, sep.c_str())) {
        r.push_back(tok);
    }
    return r;
}

void read() {
    string s, sep = "=.,";
    cin >> s >> s >> s;
    auto tokens = tokenize(s, sep + "x");
    area.x[0] = stoi(tokens[0]);
    area.x[1] = stoi(tokens[1]);

    cin >> s;
    tokens = tokenize(s, sep + "y");
    area.y[0] = stoi(tokens[0]);
    area.y[1] = stoi(tokens[1]);
}

signed main() {
    freopen("text.in", "r", stdin);
    read();
    int ansY = 0;
    for (int i = 0; i < abs(area.y[0]); i++) {
        int aux = i;
        int currY = 0;
        while (currY >= area.y[0]) {
            currY += aux;
            aux--;
            if (area.isInAreaY(currY)) {
                ansY = i;
            }
        }
    }
    int maxH = 0;
    while (ansY) {
        maxH += ansY;
        ansY--;
    }
    cout << maxH << endl;//*/
    return 0;
}
