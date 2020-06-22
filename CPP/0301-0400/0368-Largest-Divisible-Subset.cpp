class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) return {};
        sort(nums.begin(), nums.end());

        vector<int> f(nums.size(), 1);
        vector<int> solutions(nums.size(), -1);
        vector<int> res;
        int ans = 0;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && f[i] < f[j] + 1) {
                    f[i] = f[j]+1;
                    solutions[i] = j;
                }
            }
            if (f[ans] < f[i]) ans = i;
        }

        while (ans != -1) {
            res.push_back(nums[ans]);
            ans = solutions[ans];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
