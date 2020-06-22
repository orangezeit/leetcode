class Solution {
public:
    string cancel(string board) {
        bool repeat(true);
        while (repeat) {
            repeat = false;
            int i(0);
            while (i < board.length()) {
                int j(i);
                while (++j < board.length() && board[i] == board[j]) {};
                if (j - i >= 3) {
                    repeat = true;
                    int m(i), n(j);
                    while (n < board.length()) board[m++] = board[n++];
                    board.resize(board.length() - j + i);
                } else {
                    i = j;
                }
            }
        }

        return board;
    }

    int dfs(string board, unordered_map<char, int>& balls) {
        if (board.empty()) return 0;
        int i(0), c(INT_MAX);
        while (i < board.length()) {
            int j(i);
            // [i, j)
            while (++j < board.length() && board[i] == board[j]) {};
            // j - i will be 1 or 2
            if (balls.count(board[i]) && balls[board[i]] >= 3 - j + i) {
                //cout << j - i << endl;
                if (!(balls[board[i]] -= 3 - j + i)) balls.erase(board[i]);
                string new_board = cancel(board.substr(0, i) + board.substr(j));
                int temp = dfs(new_board, balls);
                if (temp != -1) c = min(c, temp + 3 - j + i);
                balls[board[i]] += 3 - j + i;
            }
            i = j;
        }
        return c == INT_MAX ? -1 : c;
    }
    int findMinStep(string board, string hand) {
        unordered_map<char, int> balls;
        for (const char& c: hand) balls[c]++;
        return dfs(board, balls);
        return 1;
    }
};
