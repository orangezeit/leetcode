class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int>> matrix(n, vector<int>(m));

        for (const vector<int>& index: indices) {
            for (int i = 0; i < m; ++i)
                matrix[index[0]][i]++;
            for (int i = 0; i < n; ++i)
                matrix[i][index[1]]++;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                ans += (matrix[i][j] % 2);
        return ans;
    }
};
