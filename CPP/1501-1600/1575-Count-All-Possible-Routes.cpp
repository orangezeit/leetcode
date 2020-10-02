class Solution {
public:
    int countRoutes(vector<int>& locs, int start, int finish, int fuel) {
        // N: num of locations, F: fuel amount
        // Space Complexity: O(N * F)
        // Time Complexity: O(N ^ 2 * F)
        int n(locs.size()), ans(0), dp[201][101] = {};
        dp[fuel][start] = 1;
        auto add = [](int& a, int b) { a = (a + b) % 1000000007; };
        for (int f = fuel; f >= 0; --f) {
            for (int prev = 0; prev < n; ++prev)
                for (int curr = 0; curr < n; ++curr) {
                    if (prev == curr || f - abs(locs[prev] - locs[curr]) < 0) continue;
                    add(dp[f - abs(locs[prev] - locs[curr])][prev], dp[f][curr]);
                }
            add(ans, dp[f][finish]);
        }
        return ans;
    }
};
