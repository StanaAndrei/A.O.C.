#include <bits/stdc++.h>
using namespace std;
vector<int> order;

struct Board {
    constexpr static int LEN = 5;
    int buffer[LEN][LEN];
    bool marked[LEN][LEN] = {};

    int getUnmarkedSum() {
        int sum = 0;
        for (int i = 0; i < LEN; i++) {
            for (int j = 0; j < LEN; j++) {
                if (!marked[i][j]) {
                    sum += buffer[i][j];
                }
            }
        }
        return sum;
    }

    void mark(int nr) {
        for (int i = 0; i < LEN; i++) {
            for (int j = 0; j < LEN; j++) {
                if (buffer[i][j] == nr) {
                    marked[i][j] = true;
                }
            }
        }
    }

    bool isWinner() {
        for (int i = 0; i < LEN; i++) {
            int sum = 0;
            for (int j = 0; j < LEN; j++) {
                sum += marked[i][j];
            }
            if (sum == LEN) {
                return true;
            }
        }

        for (int j = 0; j < LEN; j++) {
            int sum = 0;
            for (int i = 0; i < LEN; i++) {
                sum += marked[i][j];
            }
            if (sum == LEN) {
                return true;
            }
        }

        return false;
    }

    friend istream &operator >> (istream &in, Board &board) {
        for (int i = 0; i < LEN; i++) {
            for (int j = 0; j < LEN; j++) {
                cin >> board.buffer[i][j];
            }
        }
        return in;
    }
};
vector<Board> boards;

void read() {
    string s;
    getline(cin, s);
    {
        stringstream ss(s);
        while (getline(ss, s, ',')) {
            order.push_back(stoi(s));
        }
    }

    for (Board board; cin >> board;) {
        boards.push_back(board);
    }
}

void solve() {
    for (int nr : order) {
        for (auto &board : boards) {
            board.mark(nr);
            if (board.isWinner()) {
                cout << 1LL * board.getUnmarkedSum() * nr << endl;
                exit(0);
            }
        }
    }
}

signed main() {
    freopen("text.in", "r", stdin);
    read();
    solve();
    return 0;
}
