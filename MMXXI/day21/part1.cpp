#include <bits/stdc++.h>
using namespace std;
int startingPos[2];

class DeterministicDice {
    static constexpr int PERIOD = 100;
    int iteration = 1;
public:
    int roll() {
        if (iteration > PERIOD) {
            iteration = 1;
        }
        return iteration++;
    }
};

class Game {
    static constexpr int WIN_SCORE = 1000;
    static constexpr int ROLLS = 3;
    static constexpr int LEN = 10;

    int iteration = 0;
    int players[2];
    int scores[2] = {};

    void iteratePlayer(int id, DeterministicDice &deterministicDice) {
        assert(id < 2);

        int sum = 0;
        for (int i = 0; i < ROLLS; i++) {
            sum += deterministicDice.roll();
        }

        players[id] = (players[id] + sum) % LEN;
        scores[id] += players[id];
        iteration += ROLLS;
    }

public:

    Game(const int _startingPos[2]) {
        memcpy(players, _startingPos, sizeof _startingPos);
    }

    bool isOver() {
        return any_of(cbegin(scores), cend(scores), [=](int score)->bool {
            return score >= WIN_SCORE;
        });
    }

    void iterate(DeterministicDice &deterministicDice) {
        iteratePlayer(0, deterministicDice);
        if (isOver()) {
            return;
        }
        iteratePlayer(1, deterministicDice);
    }

    int64_t getAns() {
        int looserId;
        if (scores[0] < WIN_SCORE) {
            looserId = 0;
        } else {
            looserId = 1;
        }
        return 1LL * scores[looserId] * iteration;
    }
};

void read() {
    for (int i = 0; i < 2; i++) {
        string s;
        cin >> s >> s >> s >> s >> s;
        startingPos[i] = stoi(s);
    }
}

signed main() {
    freopen("text.in", "r", stdin);
    read();
    Game game(startingPos);
    DeterministicDice deterministicDice;
    while (!game.isOver()) {
        game.iterate(deterministicDice);
    }
    cout << game.getAns() << endl;//
    return 0;
}
