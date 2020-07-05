class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        unordered_set<int> extrema;
        // Time Complexity: O(mn)
        // Space Complexity: O(m + n)
        int m(matrix.size()), n(matrix[0].size());
        vector<int> lucky;
        if (m < n) {
            for (int i = 0; i < m; ++i) {
                int r(100001);
                for (int j = 0; j < n; ++j)
                    r = min(r, matrix[i][j]);
                extrema.insert(r);
            }
            for (int j = 0; j < n; ++j) {
                int c(0);
                for (int i = 0; i < m; ++i)
                    c = max(c, matrix[i][j]);
                if (extrema.count(c)) lucky.push_back(c);
            }
        } else {
            for (int j = 0; j < n; ++j) {
                int c(0);
                for (int i = 0; i < m; ++i)
                    c = max(c, matrix[i][j]);
                extrema.insert(c);
            }
            for (int i = 0; i < m; ++i) {
                int r(100001);
                for (int j = 0; j < n; ++j)
                    r = min(r, matrix[i][j]);
                if (extrema.count(r)) lucky.push_back(r);
            }
        }

        return lucky;
    }
};
