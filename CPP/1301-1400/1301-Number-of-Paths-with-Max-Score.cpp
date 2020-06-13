class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int m(board.size()), n(board[0].length());
        vector<vector<long>> scores(m, vector<long>(n)), cnts(m, vector<long>(n));

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (board[i][j] == 'X') {

                } else {
                    if (board[i][j] >= '1' && board[i][j] <= '9')
                        scores[i][j] += board[i][j] - '0';
                    long step(0), score(0);
                    if (i < m - 1 && j < n - 1) {
                        if (scores[i + 1][j + 1] > score) {
                            score = scores[i + 1][j + 1];
                            step = cnts[i + 1][j + 1];
                        } else if (scores[i + 1][j + 1] == score) {
                            step += cnts[i + 1][j + 1];
                        }
                    }
                    if (i < m - 1) {
                        if (scores[i + 1][j] > score) {
                            score = scores[i + 1][j];
                            step = cnts[i + 1][j];
                        } else if (scores[i + 1][j] == score) {
                            step += cnts[i + 1][j];
                        }
                    }
                    if (j < n - 1) {
                        if (scores[i][j + 1] > score) {
                            score = scores[i][j + 1];
                            step = cnts[i][j + 1];
                        } else if (scores[i][j + 1] == score) {
                            step += cnts[i][j + 1];
                        }
                    }
                    scores[i][j] += score;
                    cnts[i][j] = i == m - 1 && j == n - 1 ? 1 : step;
                    if (!cnts[i][j]) scores[i][j] = 0;
                    scores[i][j] %= 1000000007;
                    cnts[i][j] %= 1000000007;
                }
            }
        }

        return {scores[0][0], cnts[0][0]};
    }
};
