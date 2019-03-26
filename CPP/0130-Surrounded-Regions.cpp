    void island(vector<vector<char>>& grid, int i, int j, char a, char b) {
        grid[i][j] = b;
        
        if (j != 0) {
            if (grid[i][j-1] == a) {
                island(grid, i, j-1, a, b);
            }
        }
        
        if (j != grid[0].size()-1) {
            if (grid[i][j+1] == a) {
                island(grid, i, j+1, a, b);
            }
        }
        
        if (i != 0) {
            if (grid[i-1][j] == a) {
                island(grid, i-1, j, a, b);
            }
        }
        
        if (i != grid.size()-1) {
            if (grid[i+1][j] == a) {
                island(grid, i+1, j, a, b);
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0) {
            return;
        }
        
        for (int i = 0; i < board.size(); ++i) {
            
            if (board[i][0] == 'O') {
                island(board, i, 0, 'O', 'Z');
            }
            
            if (board[i][board[0].size()-1] == 'O') {
                island(board, i, board[0].size()-1, 'O', 'Z');
            }
        }
        
        if (board[0].size() == 0) {
            return;
        }
        
        for (int i = 0; i < board[0].size(); ++i) {
            
            if (board[0][i] == 'O') {
                island(board, 0, i, 'O', 'Z');
            }
            
            if (board[board.size()-1][i] == 'O') {
                island(board, board.size()-1, i, 'O', 'Z');
            }
        }
        
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'O') {
                    island(board, i, j, 'O', 'X');
                }
            }
        }
        
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'Z') {
                    island(board, i, j, 'Z', 'O');
                }
            }
        }
    }
