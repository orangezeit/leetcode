class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        vector<int> dp(1 << n);
        vector<int> deps(n);
        for (const auto& d: dependencies)
            deps[d[1] - 1] |= 1 << (d[0] - 1);
        dp[0] = 1;
        for (int d = 1; d <= n; ++d) {
            vector<int> tmp(1 << n);
            for (int s = 0; s < (1 << n); ++s) {
                if (!dp[s]) continue;
                int mask = 0;
                for (int i = 0; i < n; ++i)
                    if (!(s & (1 << i)) && (s & deps[i]) == deps[i])
                        mask |= (1 << i);
                if (__builtin_popcount(mask) <= k) {
                    tmp[s | mask] = 1;
                } else {
                    for (int c = mask; c; c = (c - 1) & mask)
                        if(__builtin_popcount(c) <= k)
                            tmp[s | c] = 1;
                }
                if (tmp.back()) return d;
            }
            dp.swap(tmp);
        }
        return -1;
    }
};
