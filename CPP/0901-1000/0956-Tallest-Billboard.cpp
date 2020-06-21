class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        unordered_map<int ,int> dp;
        dp[0] = 0;
        for (const int& r: rods) {
            auto cur = dp;
            for (auto& p: cur) {
                int i = p.first;
                dp[i + r] = max(dp[i + r], cur[i]);
                dp[abs(i - r)] = max(dp[abs(i - r)], cur[i] + min(i, r));
            }
        }
        return dp[0];
    }
};
