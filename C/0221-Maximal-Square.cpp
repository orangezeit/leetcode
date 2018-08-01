// Method 1
private:
    bool check(vector<vector<char>>& matrix, int x, int y, int r) {
        
        for (int i = x; i < x + r; ++i) {
            for (int j = y; j < y + r; ++j) {
                if (matrix[i][j] == '0') return false;
            }
        }
        
        return true;
    }
    
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int k = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int r = k + 1; r <= min(m-i, n-j); ++r) {
                    if (check(matrix, i, j, r)) {
                        k = r;
                    } else {
                        break;
                    }
                }
            }
        }
        
        return k * k;
    }
// Method 2
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int m = matrix.size();
        int n = matrix[0].size();
        int k = 0;
        
        vector<vector<int>> dp(m ,vector<int>(n, 0));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] += matrix[i][j] - '0';
                if (i) dp[i][j] += dp[i-1][j];
                if (j) dp[i][j] += dp[i][j-1];
                if (i && j) dp[i][j] -= dp[i-1][j-1];
            }
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int r = min(m-i,n-j); r >= k+1; --r) {
                    int ones = dp[i+r-1][j+r-1];
                    
                    if (i && j) ones += dp[i-1][j-1];
                    if (i) ones -= dp[i-1][j+r-1];
                    if (j) ones -= dp[i+r-1][j-1];
                    
                    if (ones == r * r) {
                        k = max(k, r);
                        break;
                    }
                }
            }
        }
        
        return k * k;
    }

// Method 3
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        int k = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] - '1') continue;
                
                i == 0 || j == 0 ? dp[i][j] = 1 : dp[i][j] = min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]) + 1;
                k = max(k, dp[i][j]);
            }
        }
        
        return k * k;
    }
