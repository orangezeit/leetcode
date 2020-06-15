class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        // Time Complexity: O(n)
        // Space Complexity: O(n)
        vector<vector<int>> diagnoals;

        for (int i = 0; i < nums.size(); ++i)
            for (int j = 0; j < nums[i].size(); ++j) {
                if (diagnoals.size() == i + j) diagnoals.emplace_back(vector<int>());
                diagnoals[i + j].emplace_back(nums[i][j]);
            }

        vector<int> ans;

        for (const vector<int>& d: diagnoals)
			ans.insert(ans.end(), d.rbegin(), d.rend());

        return ans;
    }
};
