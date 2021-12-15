#include <bits/stdc++.h>
using namespace std;
using Point = pair<int, int>;
#define fi first
#define se second
vector<string> matrix;
int n, m;
constexpr int NR_DIRS = 4;
constexpr array<int, NR_DIRS> dirI = {0, 0, 1, -1};
constexpr array<int, NR_DIRS> dirJ = {1, -1, 0, 0};

struct Cmp {
    bool operator() (const Point &p1, const Point &p2) {
        const auto &[line1, col1] = p1;
        const auto &[line2, col2] = p2;
        return matrix[line1][col1] > matrix[line2][col2];
    }
};

void read() {
    for (string line; getline(cin, line);) {
        matrix.push_back(line);
    }
    n = matrix.size();
    m = matrix[0].size();
}

bool isInside(const int &i, const int &j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

void dijkstra() {
    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
    priority_queue<Point, vector<Point>, Cmp> q;
    q.emplace(0, 0);
    dp[0][0] = 0;
    while (!q.empty()) {
        const auto [i, j] = q.top();
        q.pop();
        for (int dir = 0; dir < NR_DIRS; dir++) {
            int newI = i + dirI[dir];
            int newJ = j + dirJ[dir];
            if (isInside(newI, newJ) && dp[newI][newJ] > dp[i][j] + matrix[newI][newJ] - '0') {
                dp[newI][newJ] = dp[i][j] + matrix[newI][newJ] - '0';
                q.emplace(newI, newJ);
            }
        }//*/
    }//*/
    cout << dp[n - 1][m - 1] << endl;
}

signed main() {
    freopen("text.in", "r", stdin);
    read();
    dijkstra();
    return 0;
}
