class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Time Complexity: O(2^N)
        // Space Complexity: O(2^N)
        sort(nums.begin(), nums.end());
        vector<int> subset;
        vector<vector<int>> ans;
        function<void(int)> dfs = [&](int k) {
            ans.emplace_back(subset);
            for (int i = k; i < nums.size(); ++i) {
                if (i != k && nums[i] == nums[i - 1]) continue;
                subset.emplace_back(nums[i]);
                dfs(i + 1);
                subset.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
};
