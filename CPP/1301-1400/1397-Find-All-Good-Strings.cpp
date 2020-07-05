class Solution {
public:
    int findGoodStrings(int n, string s1, string s2, string evil) {
        const size_t m(evil.length());
        const int mod(1e9 + 7);
        int dp[501][51][2][2] = {};
        int lps[51] = {};
        for (int i = 1, j = 0; i < m; i++) {
            while (j > 0 && evil[i] != evil[j])
                j = lps[j - 1];
            if (evil[i] == evil[j]) lps[i] = ++j;
        }

        function<int(int, int, bool, bool)> dfs = [&](int i, int j, bool lb, bool ub) {
            if (j == m) return 0;
            if (i == n) return 1;
            if (dp[i][j][lb][ub]) return dp[i][j][lb][ub];
            char first(lb ? s1[i] : 'a'), last(ub ? s2[i] : 'z');
            int res(0);
            for (char c = first; c <= last; ++c) {
                int k = j;
                while (k > 0 && evil[k] != c) k = lps[k - 1];
                if (c == evil[k]) k++;
                res = (res + dfs(i + 1, k, lb && c == first, ub && c == last)) % mod;
            }
            return dp[i][j][lb][ub] = res;
        };

        return dfs(0, 0, true, true);
    }
};
