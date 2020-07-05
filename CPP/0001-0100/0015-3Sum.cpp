class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Time Complexity: O(N^2)
        // Space Complexity: O(N^2) ?
        if (nums.size() < 3) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i == 0 || nums[i - 1] != nums[i]) {
                int j(i + 1), k(nums.size() - 1);
                while (j < k) {
                    if (nums[j] + nums[k] == -nums[i]) {
                        ans.push_back({nums[i], nums[j], nums[k]});
                        while (j < k && nums[j + 1] == nums[j++]) {};
                        while (j < k && nums[k - 1] == nums[k--]) {};
                    } else {
                        nums[j] + nums[k] < -nums[i] ? j++ : k--;
                    }
                }
            }
        }


        return ans;
    }
};
