#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
using Coord = pair<int, int>;
using Fold = pair<char, int>;
set<Coord> coords;
Fold fold;

vector<string> tokenize(string s, const string &sep) {
    vector<string> r;
    char *arr = &s[0];
    for (char *tok = strtok(arr, sep.c_str()); tok; tok = strtok(NULL, sep.c_str())) {
        r.push_back(tok);
    }
    return r;
}

void read() {
    for (string line; getline(cin, line) && line != "";) {
        vector<string> tokens = tokenize(line, ",");
        coords.emplace(stoi(tokens[0]), stoi(tokens[1]));
    }

    string s;
    cin >> s >> s >> s;
    fold = make_pair(s[0], stoi(s.substr(2)));
}

void foldX(set<Coord> &coords, int x) {
    set<Coord> ans;
    for (auto coord : coords) {
        if (coord.fi < x) {
            ans.insert(coord);
        } else {
            ans.emplace(x * 2 - coord.fi, coord.se);
        }
    }
    coords = ans;
}

void foldY(set<Coord> &coords, int y) {
    set<Coord> ans;
    for (auto coord : coords) {
        if (coord.se < y) {
            ans.insert(coord);
        } else {
            ans.emplace(coord.fi, y * 2 - coord.se);
        }
    }
    coords = ans;
}


signed main() {
    freopen("text.in", "r", stdin);
    read();
    if (fold.fi == 'x') {
        foldX(coords, fold.se);
    } else {
        foldY(coords, fold.se);
    }
    cout << coords.size() << endl;
    return 0;
}
