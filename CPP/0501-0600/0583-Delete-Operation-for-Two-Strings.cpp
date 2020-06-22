class Solution {
public:
    int minDistance(string w1, string w2) {
        int s1(w1.length()), s2(w2.length());
        vector<vector<int>> dp(s1, vector<int>(s2, 0));

        for (int i = 0; i < s1; ++i) {
            for (int j = 0; j < s2; ++j) {
                dp[i][j] = w1[i] == w2[j] ? (i && j ? dp[i-1][j-1] : 0) + 1 : max(i ? dp[i-1][j] : 0, j ? dp[i][j-1] : 0);
            }
        }
        return s1 + s2 - 2 * (s1 && s2 ? dp.back().back() : 0);
    }
};
