class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> rec;

        for (const int& n: nums) {
            if (rec.count(n)) continue;
            rec[n] = 1;
            int left = rec.count(n - 1) ? rec[n - 1] : 0;
            int right = rec.count(n + 1) ? rec[n + 1] : 0;
            rec[n - left] = rec[n + right] = left + right + 1;
        }

        int ans(0);
        for (const auto& [k, v]: rec) ans = max(ans, v);
        return ans;
    }
};
