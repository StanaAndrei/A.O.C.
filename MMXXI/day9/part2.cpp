#include <bits/stdc++.h>
using namespace std;
vector<string> matrix;
int n, m;
constexpr int NR_DIRS = 4;
constexpr int dirI[NR_DIRS] = {0, 0, -1, 1};
constexpr int dirJ[NR_DIRS] = {1, -1, 0, 0};
vector<vector<bool>> vis;
vector<int> lens;

bool isInside(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

void read() {
    for (string s; getline(cin, s);) {
        matrix.push_back(s);
    }
    n = matrix.size();
    m = matrix[0].size();
}


int getBasinSz(int startI, int startJ) {
    queue<pair<int, int>> q;
    q.emplace(startI, startJ);
    int r = 0;
    vis[startI][startJ] = true;
    while (!q.empty()) {
        const auto &[i, j] = q.front();
        q.pop();
        r++;
        for (int dir = 0; dir < NR_DIRS; dir++) {
            int newI = i + dirI[dir];
            int newJ = j + dirJ[dir];
            if (isInside(newI, newJ) && matrix[newI][newJ] != '9' && !vis[newI][newJ]) {
                q.emplace(newI, newJ);
                vis[newI][newJ] = true;
            }
        }
    }
    return r;
}

void solve() {
    vis.resize(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && matrix[i][j] != '9') {
                lens.push_back(getBasinSz(i, j));
            }
        }
    }
}

signed main() {
    freopen("text.in", "r", stdin);
    read();
    solve();
    sort(rbegin(lens), rend(lens));
    cout << 1ULL * lens[0] * lens[1] * lens[2] << endl;
    return 0;
}
