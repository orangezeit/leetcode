private:
    int m, n;
    int d[8][2] = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};
    
    bool isValid(int x, int y) {
        return (x >= 0 && x < m) && (y >= 0 && y < n);
    }
    
    void traverse(vector<vector<char>>& board, vector<int> click) {
        int c = 0;
        
        for (int i = 0; i < 8; ++i) {
            if (isValid(click[0] + d[i][0], click[1] + d[i][1])) {
                if (board[click[0] + d[i][0]][click[1] + d[i][1]] == 'M') {
                    c++;
                }
            }
        }
        
        if (c > 0) {
            board[click[0]][click[1]] = '0' + c;
            return;
        } else {
            board[click[0]][click[1]] = 'B';
            for (int i = 0; i < 8; ++i) {
                if (isValid(click[0] + d[i][0], click[1] + d[i][1]) && board[click[0] + d[i][0]][click[1] + d[i][1]] != 'B') {
                    traverse(board, {click[0] + d[i][0], click[1] + d[i][1]});
                }
            }
        }
    }
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        m = board.size();
        n = board[0].size();
        
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        } else {
            int c = 0;
            
            for (int i = 0; i < 8; ++i) {
                if (isValid(click[0] + d[i][0], click[1] + d[i][1])) {
                    if (board[click[0] + d[i][0]][click[1] + d[i][1]] == 'M') {
                        c++;
                    }
                }
            }
            
            if (c) {
                board[click[0]][click[1]] = '0' + c;
                return board;
            }
            
            traverse(board, click);
            return board;
        }
    }
