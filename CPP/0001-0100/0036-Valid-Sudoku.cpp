    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                for (int k = 0; k < 9 ; ++k) {
                    if (board[i][j] == board[i][k] && j != k) return false;
                    if (board[k][j] == board[i][j] && i != k) return false;
                }
                for (int k = i/3*3; k < i/3*3+3; ++k)
                    for (int l = j/3*3; l < j/3*3+3; ++l)
                        if (board[i][j] == board[k][l] && i != k && j != l)
                            return false;
            }
        return true;
    }
