class Solution {
public:
    int countSubstrings(string s) {
        int k(s.length()), cnt(0);
        vector<vector<bool>> dp(k, vector<bool>(k));
        for (int len = 1; len <= k; ++len)
            for (int i = 0; i + len - 1 < k; ++i) {
                int j = i + len - 1;
                if (dp[i][j] = s[i] == s[j] && (i + 2 <= j ? dp[i+1][j-1]: true))
                    cnt++;
            }
        return cnt;
    }
};
