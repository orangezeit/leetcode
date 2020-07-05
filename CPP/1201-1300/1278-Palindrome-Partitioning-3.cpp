class Solution {
public:
    unordered_map<string, int> memo;
    map<pair<string, int>, int> memo2;

    int change(string s) {
        if (memo.count(s)) return memo[s];
        int c(0);
        for (int i = 0; i < s.length() / 2; ++i) {
            if (s[i] != s[s.length() - i - 1])
                c++;
        }
        return memo[s] = c;
    }
    int dfs(string s, int k) {
        if (memo2.count({s, k})) return memo2[{s, k}];
        if (s.length() < k) return memo2[{s, k}] = -1;
        if (k == 1) return memo2[{s, k}] = change(s);
        else {
            int c(INT_MAX);
            for (int i = 1; i <= s.length() - 1; ++i) {
                int temp = dfs(s.substr(i), k - 1);
                if (temp != -1)
                    c = min(c, change(s.substr(0, i)) + temp);
            }
            return memo2[{s, k}] = c == INT_MAX ? -1 : c;
        }

    }
    int palindromePartition(string s, int k) {
        return dfs(s, k);
    }
};
