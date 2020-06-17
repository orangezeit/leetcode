class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<bitset<300>, int> m;
        int ans(0);

        for (int i = 0; i < matrix.size(); ++i) {
            bitset<300> bs;
            for (int j = 0; j < matrix[0].size(); ++j)
                bs[j] = matrix[i][0] ? matrix[i][j] : !matrix[i][j];
            ans = max(ans, ++m[bs]);
        }

        return ans;
    }
};
