private:
    int m, n;
    vector<vector<bool>> visited;
    int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    bool valid(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    
public:
    void travel(const vector<vector<char>>& board, const string& word, int x, int y, int k, bool& found) {
        if (k == word.length()-1) {
            found = true;
            return;
        } else {
            for (int i = 0; i < 4; ++i) {
                if (valid(x + d[i][0], y + d[i][1])) {
                    if (!visited[x + d[i][0]][y + d[i][1]] && board[x + d[i][0]][y + d[i][1]] == word[k+1]) {
                        visited[x][y] = true;
                        travel(board, word, x + d[i][0], y + d[i][1], k+1, found);
                        if (found) {
                            return;
                        }
                        visited[x][y] = false;
                    }
                }
            }
        }
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if (word.length() == 0) {
            return false;
        } else if (board.size() == 0) {
            return false;
        } else if (board[0].size() == 0) {
            return false;
        }
        
        m = board.size();
        n = board[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    bool found = false;
                    travel(board, word, i, j, 0, found);
                    if (found) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
