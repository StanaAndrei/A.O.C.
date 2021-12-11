#include <bits/stdc++.h>
using namespace std;
constexpr int NR_STEPS = 100;
vector<vector<int>> matrix;
int n, m, ans;

void getInput() {
    for (string line; getline(cin, line);) {
        matrix.push_back({});
        for (const char &ch : line) {
            matrix.back().push_back(ch - '0');
        }
    }
    n = matrix.size();
    m = matrix[0].size();
}

void increment() {
    for (auto &line : matrix) {
        for (int &elem : line) {
            elem++;
        }
    }
}

bool isInside(const int &i, const int &j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

void step() {
    increment();
    vector<vector<int>> flashed(n, vector<int>(m));
    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] > 9) {
                    flashed[i][j] = true;
                    ans++;
                    flag = true;
                    matrix[i][j] = 0;
                    for (int ii = i - 1; ii <= i + 1; ii++) {
                        for (int jj = j - 1; jj <= j + 1; jj++) {
                            if (isInside(ii, jj) && (ii != i || jj != j) && matrix[ii][jj] && !flashed[ii][jj]) {
                                matrix[ii][jj]++;
                            }
                        }
                    }
                }
            }
        }
    }//*/
}

signed main() {
    freopen("text.in", "r", stdin);
    getInput();
    for (int i = 0; i < NR_STEPS; i++) {
        step();
    }
    cout << ans << endl;
    return 0;
}
