#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
using Point = pair<int, int>;
using Line = pair<Point, Point>;
map<Point, int> freq;

istream &operator >> (istream &iStream, Point &point) {
    char comma;
    iStream >> point.fi >> comma >> point.se;
    return iStream;
}

istream &operator >> (istream &iStream, Line &line) {
    char arrow[5];
    iStream >> line.fi >> arrow >> line.se;
    return iStream;
}

bool isHorizOrVert(const Line &line) {
    bool ok = false;
    ok |= (line.fi.fi == line.se.fi);
    ok |= (line.fi.se == line.se.se);
    return ok;
}

void process(Line line) {
    if (line.fi.fi > line.se.fi) {
        swap(line.fi, line.se);
    }
    if (line.fi.se > line.se.se) {
        swap(line.fi, line.se);
    }
    for (int x = line.fi.fi; x <= line.se.fi; x++) {
        for (int y = line.fi.se; y <= line.se.se; y++) {
            freq[make_pair(x, y)]++;
        }
    }
}

signed main() {
    freopen("text.in", "r", stdin);
    vector<Line> lines;
    for (Line line; cin >> line;) {
        lines.push_back(line);
    }
    for (const auto &line : lines) {
        if (isHorizOrVert(line)) {
            process(line);
        }
    }
    int ans = 0;
    for (auto it = begin(freq); it != end(freq); it++) {
        if (it->se > 1) {
            ans++;
        }
    }
    cout << ans << endl;//*/
    return 0;
}
