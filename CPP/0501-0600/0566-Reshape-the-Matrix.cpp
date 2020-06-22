class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size();
        int n = nums[0].size();
        if (m * n != r * c) return nums;

        vector<vector<int>> ans(r, vector<int>(c));

        for (int k = 0; k < m * n; ++k)
            ans[k / c][k % c] = nums[k / n][k % n];
        return ans;
    }
};
