class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        nums.emplace_back(0);
        int prev(-1), n(nums.size()), ans(0);
        for (int i = 0; i < n; ++i) {
            if (nums[i]) continue;
            int sign(0), first(-1), last(-1);
            for (int j = prev + 1; j < i; ++j)
                if (nums[j] < 0) {
                    if (first == -1) first = j;
                    last = j;
                    sign = 1 - sign;
                }
            ans = max(ans, (sign ? max(max(first - prev, i - first), max(last - prev, i - last)) : i - prev) - 1);
            prev = i;
        }
        return ans;
    }
};
