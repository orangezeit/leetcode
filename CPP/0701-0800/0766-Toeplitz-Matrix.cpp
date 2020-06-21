class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < n; ++i) {
            int j(0), k(i);
            while (j < m-1 && k < n-1)
                if (matrix[++j][++k] != matrix[0][i])
                    return false;
        }

        for (int i = 0; i < m; ++i) {
            int j(i), k(0);
            while (j < m-1 && k < n-1)
                if (matrix[++j][++k] != matrix[i][0])
                    return false;
        }

        return true;
    }
};
