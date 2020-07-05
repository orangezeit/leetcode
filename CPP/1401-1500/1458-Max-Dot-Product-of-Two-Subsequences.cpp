class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int c = -1e9;
        vector<vector<int>> dp(n, vector<int>(m));
        vector<vector<int>> dpmax(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                dp[i][j] = nums1[i] * nums2[j] + max(0, i && j ? dpmax[i-1][j-1] : 0);
                dpmax[i][j] = max(dp[i][j], max(i ? dpmax[i-1][j] : c, j ? dpmax[i][j-1] : c));
            }

        return dpmax[n-1][m-1];
    }
};
