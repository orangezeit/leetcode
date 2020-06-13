class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int row(board.size()), col(board[0].size());
        bool todo(false);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                int v = abs(board[i][j]);
                if (v && i && v == abs(board[i-1][j]) && i < row - 1 && v == abs(board[i+1][j])) {
                    board[i][j] = board[i-1][j] = board[i+1][j] = -v;
                    todo = true;
                }
                if (v && j && v == abs(board[i][j-1]) && j < col - 1 && v == abs(board[i][j+1])) {
                    board[i][j] = board[i][j-1] = board[i][j+1] = -v;
                    todo = true;
                }
            }
        }
        /*
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                cout << board[i][j] << " ";
            }cout << endl;
        }cout << endl;*/
        for (int c = 0; c < col; ++c) {
            int wr = row;
            for (int r = row - 1; r >= 0; --r)
                if (board[r][c] > 0)
                    board[--wr][c] = board[r][c];
            while (wr)
                board[--wr][c] = 0;
        }

        return todo ? candyCrush(board) : board;
    }
};
