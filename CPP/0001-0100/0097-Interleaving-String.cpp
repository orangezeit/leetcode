class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Top Down DP
        // Time Complexity: O(N1 * N2)
        // Space Complexity: O(N1 * N2)
        if (s1.length() + s2.length() != s3.length()) return false;
        unordered_map<int, bool> rec;
        int n1(s1.length()), n2(s2.length()), n3(s3.length());
        rec[n1 * n3 + n2] = true;
        function<bool(int, int)> dfs = [&](int i, int j) {
            return rec.count(i * n3 + j) ? rec[i * n3 + j] :
                                           rec[i * n3 + j] = (i < n1 && s1[i] == s3[i + j] ? dfs(i + 1, j) : false) ||
                                                             (j < n2 && s2[j] == s3[i + j] ? dfs(i, j + 1) : false);
        };
        return dfs(0, 0);
    }

    bool isInterleave(string s1, string s2, string s3) {
        // Bottom Up DP
        // Time Complexity: O(N1 * N2)
        // Space Complexity: O(N1 * N2)
        if (s1.length() + s2.length() != s3.length()) return false;
        int n1(s1.length()), n2(s2.length());
        bool dp[n1 + 1][n2 + 1] = {};
        dp[0][0] = true;
        for (int i = 1; i <= n1; ++i)
            for (int j = 1; j <= n2; ++j)
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                           (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
        return dp[n1][n2];
    }
};
