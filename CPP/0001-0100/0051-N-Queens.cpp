private:
    vector<vector<string>> solutions;
public:
    void fillHelper(int x, int y, int n, vector<string> solution) {
        solution[x][y] = 'Q';
        
        for (int i = 0; i < n; ++i) {
            if (solution[x][i] != 'Q') {
                solution[x][i] = '.';
            }
            if (solution[i][y] != 'Q') {
                solution[i][y] = '.';
            }
        }
        
        int s = x;
        int t = y;
        
        while (s != 0 && t != 0) {
            solution[--s][--t] = '.';
        }
        
        s = x;
        t = y;
        
        while (s != n-1 && t != n-1) {
            solution[++s][++t] = '.';
        }
        
        s = x;
        t = y;
        
        while (s != 0 && t != n-1) {
            solution[--s][++t] = '.';
        }
        
        s = x;
        t = y;
        
        while (s != n-1 && t != 0) {
            solution[++s][--t] = '.';
        }
        
        if (x != n-1) {
            for (int i = 0; i < n; ++i) {
                if (solution[x+1][i] != '.') {
                    fillHelper(x+1, i, n, solution);
                }
            }
        } else {
            solutions.push_back(solution);
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        for (int i = 0; i < n; ++i) {
            fillHelper(0, i, n, vector<string>(n, string(n, ' ')));
        }
        
        return solutions;
    }
