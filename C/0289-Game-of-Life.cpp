private:
    int m, n;
    int d[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    bool isValid(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        m = board.size();
        n = board[0].size();
        
        vector<vector<int>> next = board;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int neighbor = 0;
                
                for (int k = 0; k < 8; ++k) {
                    if (isValid(i + d[k][0], j + d[k][1])) {
                        if (board[i + d[k][0]][j + d[k][1]]) {
                            neighbor++;
                            if (neighbor > 3) {
                                break;
                            }
                        }
                    }
                }
                
                board[i][j] && neighbor == 2 || neighbor == 3 ? next[i][j] = 1 : next[i][j] = 0;
            }
        }
        
        board = next;
    }
