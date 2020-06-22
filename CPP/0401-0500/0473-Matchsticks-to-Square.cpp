class Solution {
public:
    bool dfs(int curr, const vector<int>& nums, vector<int>& fs) {
        if (curr == nums.size()) return true;

        for (int i = 0; i < 4; ++i) {
            if (fs[i] >= nums[curr]) {
                fs[i] -= nums[curr];
                if (dfs(curr + 1, nums, fs))
                    return true;
                fs[i] += nums[curr];
            }
        }
        return false;
    }

    bool makesquare(vector<int>& nums) {
        if (nums.empty()) return false;
        int side(0);
        for (const int& n: nums)
            side += n;
        if (side % 4) return false;
        sort(nums.rbegin(), nums.rend());
        vector<int> fs(4, side / 4);
        return dfs(0, nums, fs);

    }
};
