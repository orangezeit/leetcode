class Solution {
public:
    void battle(vector<vector<char>>& grid, int i, int j) {
        if (j != 0) {
            if (grid[i][j-1] == 'X') {
                grid[i][j-1] = 'Y';
                battle(grid, i, j-1);
            }
        }

        if (j != grid[0].size()-1) {
            if (grid[i][j+1] == 'X') {
                grid[i][j+1] = 'Y';
                battle(grid, i, j+1);
            }
        }

        if (i != 0) {
            if (grid[i-1][j] == 'X') {
                grid[i-1][j] = 'Y';
                battle(grid, i-1, j);
            }
        }

        if (i != grid.size()-1) {
            if (grid[i+1][j] == 'X') {
                grid[i+1][j] = 'Y';
                battle(grid, i+1, j);
            }
        }

        return;
    }

    int countBattleships(vector<vector<char>>& board) {
        int num = 0;

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'X') {
                    board[i][j] = 'Y';
                    battle(board, i, j);
                    num++;
                }
            }
        }

        return num;
    }
};
