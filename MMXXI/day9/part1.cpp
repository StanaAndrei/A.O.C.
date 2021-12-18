#include <bits/stdc++.h>
using namespace std;
vector<string> matrix;
int n, m, sum;
constexpr int NR_DIRS = 4;
constexpr int dirI[NR_DIRS] = {0, 0, -1, 1};
constexpr int dirJ[NR_DIRS] = {1, -1, 0, 0};

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

bool isLowPoint(int i, int j) {
    bool ok = true;
    for (int dir = 0; dir < NR_DIRS; dir++) {
        int newI = i + dirI[dir];
        int newJ = j + dirJ[dir];
        if (isInside(newI, newJ)) {
            ok &= matrix[newI][newJ] > matrix[i][j];
        }
    }
    return ok;
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (isLowPoint(i, j)) {
                sum += matrix[i][j] - '0' + 1;
            }
        }
    }
}

signed main() {
    freopen("text.in", "r", stdin);
    read();
    solve();
    cout << sum << endl;
    return 0;
}
