class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = (int)str1.length();
        int m = (int)str2.length();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                dp[i][j] = str1[i-1] == str2[j-1] ? dp[i-1][j-1] + 1 : max(dp[i-1][j], dp[i][j-1]);

        string ans;

        while (n || m) {
            //char c;
            if (m == 0) {
                ans += str1[--n];
            } else if (n == 0) {
                ans += str2[--m];
            } else if (str1[n-1] == str2[m-1]) {
                ans += str1[--n] = str2[--m];
            } else if (dp[n-1][m] == dp[n][m]) {
                ans += str1[--n];
            } else if (dp[n][m-1] == dp[n][m]) {
                ans += str2[--m];
                //i++;
            }
            //cout << ans << endl;
        }
        //cout << i << " " << j << endl;
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
