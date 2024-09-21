#include <bits/stdc++.h>
using namespace std;
const int NMAX = 600;
const string TARGET = "shinygold";
map<string, int> colToNum;
#define fi first
#define se second
vector<pair<int, int>> edges[NMAX];
int nrcol, ans, start;

bool aBag(string s) {
    return s == "bag" || s == "bags";
}

vector<string> strSplit(string s, string sep) {
    const size_t n = s.size();
    vector<string> splited;
    int st = 0, fin = n - 1;
    for (size_t i = 0; i <= n; i++) {
        if (sep.find(s[i]) != string::npos || i == n) {
            fin = i;
            string temp = string(s.begin() + st, s.begin() + fin);
            if (!temp.empty())
                splited.push_back(temp);
            st = i + 1;
        }
    }
    return splited;
}

void addEdge(string from, string to, int nr) {
    if (!colToNum.count(from))
        colToNum[from] = ++nrcol;
    if (from == TARGET)
        start = colToNum[from];//TARGET id
    if (!colToNum.count(to))
        colToNum[to] = ++nrcol;
    edges[colToNum[from]].push_back(make_pair(colToNum[to], nr));
}

uint64_t dfs(int node) {
    ans++;
    uint64_t r = 0;
    for (auto it : edges[node]) {
        r += dfs(it.fi) * it.se;
    }
    return r + 1;
}

int main() {
    freopen("text.in", "r", stdin);
    string s;
    while (getline(cin, s)) {
        vector<string> splited = strSplit(s, ",. ");
        if (s.empty() || find(splited.begin(), splited.end(), "other") != splited.end())
            continue;
        int it = 0;
        string fromCol;
        while (!aBag(splited[it]))
            fromCol += splited[it++];
        it += 2;
        //cerr << "FROM:" << fromCol << endl;
        string toCol;
        int nr;
        for (; it < (int)splited.size(); it++) {
            if (isdigit(splited[it][0])) {
                nr = atoi(splited[it].c_str());
                continue;
            }
            if (!aBag(splited[it])) {
                toCol += splited[it];
            } else {
                //cerr << "TO:" << toCol << "NR:" << nr << endl;
                addEdge(fromCol, toCol, nr);
                toCol = "";
            }
        }
    }//*/
    cout << dfs(start) - 1 << endl;
    return 0;
}
