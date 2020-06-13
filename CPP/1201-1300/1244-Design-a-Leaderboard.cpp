class Leaderboard {
public:
    map<int, int> board;
    unordered_map<int, int> players;
    Leaderboard() {

    }

    void addScore(int playerId, int score) {
        if (players.count(playerId)) {
            int c = players[playerId];
            players[playerId] += score;
            board[c]--;
            if (board[c] == 0) board.erase(c);
            board[players[playerId]]++;
        } else {
            players[playerId] = score;
            board[score]++;
        }
    }

    int top(int K) {
        int s(0);
        auto p = board.end();
        while (true) {
            --p;
            if (K > p->second) {
                K -= p->second;
                s += p->first * p->second;
            } else {
                s += p->first * K;
                break;
            }
            if (p == board.begin()) break;
        }
        return s;
    }

    void reset(int playerId) {
        board[players[playerId]]--;
        if (board[players[playerId]] == 0) board.erase(players[playerId]);
        players[playerId] = 0;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
