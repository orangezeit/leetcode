class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<vector<int>> info(s.length() + 1, vector<int>(26, 0));
        vector<int> v(26, 0);

        for (int k = 1; k <= s.length(); ++k) {
            v[s[k-1] - 'a']++;
            for (int i = 0; i < 26; ++i)
                info[k][i] = v[i];
        }

        vector<bool> ans(queries.size());

        for (int i = 0; i < queries.size(); ++i) {
            int t(0);
            for (int j = 0; j < 26; ++j)
                t += (info[queries[i][1] + 1][j] - info[queries[i][0]][j]) % 2;
            ans[i] = t / 2 <= queries[i][2];
        }
        return ans;
    }
};
