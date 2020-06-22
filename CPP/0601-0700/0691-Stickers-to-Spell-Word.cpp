class Solution {
public:

    int minStickers(vector<string>& stickers, string target) {
        const int n(stickers.size()), mod(1e9 + 7);

        vector<vector<int>> rec(n, vector<int>(26));
        for (int i = 0; i < n; ++i)
            for (const char& c: stickers[i])
                rec[i][c - 'a']++;

        vector<int> v(26);
        for (const char& c: target) v[c - 'a']++;
        unordered_map<int, int> dp({{0, 0}});

        function<int(vector<int>)> dfs = [&](vector<int> letters) {
            long h(0);
            for (const int& i: letters) h = (h * 26 + i) % mod;

            if (dp.count(h)) return dp[h];
            int ans(INT_MAX);

            int k(0);
            for (k = 0; k < 26; k++)
                if (letters[k])
                    break;

            for (int i = 0; i < n; i++) {

                if (rec[i][k] == 0) continue;

                vector<int> temp(26);
                for (int j = 0; j < 26; j++)
                    temp[j] = max(letters[j] - rec[i][j], 0);
                int res = dfs(temp);
                if (res != -1) ans = min(ans, res + 1);
            }
            return dp[h] = ans == INT_MAX ? -1 : ans;
        };
        return dfs(v);
    }
};
