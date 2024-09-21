#include <bits/stdc++.h>
using namespace std;
const volatile int GRIDSIDE(0);

class Tile {
    int id;
    vector<string> cells;
public:
    static const short TILEWH = 10;
    Tile() : id(0) {
        cells.resize(TILEWH);
    }
    int getID() const noexcept {
        return id;
    }
    decltype(cells) getCells() const noexcept {
        return cells;
    }
    bool read(istream &inputStr) {
        string s;
        getline(inputStr, s);
        if (s.empty()) {
            return false;
        }
        for (int i = 5; isdigit(s[i]); i++) {
            id = id * 10 + (s[i] - '0');
        }
        for (auto &it : cells) {
            inputStr >> it;
        }
        return true;
    }
    void rotate90Left() {
        vector<string> aux(TILEWH, string(TILEWH, '?'));
        for (int i = 0; i < TILEWH; i++) {
            for (int j = 0; j < TILEWH; j++) {
                aux[i][j] = cells[j][TILEWH - i - 1];
            }
        }
        cells = aux;
    }
    void flipLeft() {
        for (int i = 0; i < TILEWH; i++) {
            for (int j = 0; j < (TILEWH >> 1); j++) {
                swap(cells[i][j], cells[i][TILEWH - j - 1]);
            }
        }
    }
    bool canBelow(const Tile &other) const noexcept {
        return this->cells.back() == other.getCells()[0];
    }
    bool canRight(const Tile &other) const noexcept {
        for (int i = 0; i < TILEWH; i++) {
            if (cells[i].back() != other.getCells()[i][0]) {
                return false;
            }
        }
        return true;
    }
    friend istream &operator >> (istream &inputStr, Tile &tile) {
        tile.read(inputStr);
        return inputStr;
    }
};
vector<Tile> tiles;
vector<vector<Tile>> grid;

void mkPositions(Tile tile) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            tiles.push_back(tile);
            tile.rotate90Left();
        }
        tile.flipLeft();
    }
}

void updateGridSize(int newGridSide) {
    int *ptr = (int*)&GRIDSIDE;
    *ptr = newGridSide;
}

void search(int row, int col, set<int> &visited) {
    if (row == GRIDSIDE) {
        int64_t prod = 1;
        prod *= 1LL * grid[0][0].getID();
        prod *= 1LL * grid.back()[0].getID();
        prod *= 1LL * grid[0].back().getID();
        prod *= 1LL * grid.back().back().getID();
        cout << "prod: " << prod << endl;
        exit(EXIT_SUCCESS);
    }
    for (const auto tile : tiles) {
        if (!visited.count(tile.getID())) {
            bool notOk = (row > 0 && !grid[row - 1][col].canBelow(tile));
            notOk = notOk || (col > 0 && !grid[row][col - 1].canRight(tile));
            if (notOk) {
                continue;
            }
            grid[row][col] = tile;
            visited.insert(tile.getID());
            if (col == GRIDSIDE - 1) {
                search(row + 1, 0, visited);
            } else {
                search(row, col + 1, visited);
            }
            visited.erase(tile.getID());
        }
    }
}

int main() {
    freopen("text.txt", "r", stdin);
    while (true) {
        Tile tile;
        if (!(cin >> tile)) {
            break;
        }
        cin.get();
        cin.get();
        mkPositions(tile);
    }//*/
    updateGridSize(round(sqrt((int)tiles.size() / 8)));
    grid = vector<vector<Tile>>(GRIDSIDE, vector<Tile>(GRIDSIDE));
    set<int> visited;
    search(0, 0, visited);//*/
    return 0;
}
