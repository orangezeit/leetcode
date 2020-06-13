class Solution {
public:
    string repeat(string s, int k) {
        string res;
        while (k--) res += s;
        return res;
    }

    string encode(string s) {
        int n(s.length());
        vector<vector<string>> dp(n, vector<string>(n));

        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;

                string str = s.substr(i, len);
                dp[i][j] = str;

                for (int k = 1; k < len; ++k)
                    if (!(len % k) && repeat(s.substr(i, k), len / k) == str) {
                        string temp = to_string(len / k) + '[' + dp[i][i + k - 1] + ']';
                        if (temp.length() < dp[i][j].length())
                            dp[i][j] = temp;
                    }

                for (int k = i; k < j; ++k)
                    if (dp[i][k].length() + dp[k + 1][j].length() < dp[i][j].length())
                        dp[i][j] = dp[i][k] + dp[k + 1][j];
            }
        }

        return dp[0][n - 1];
    }
};
