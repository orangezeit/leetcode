class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> indices(nums.size(), 0);
        set<pair<int, int>> range;

        for (int i = 0; i < nums.size(); ++i) {
            range.insert({nums[i][0], i});
        }

        vector<int> ans(2);
        ans[0] = (*range.begin()).first;
        ans[1] = (*range.rbegin()).first;
        int min_range = ans[1] - ans[0];

        while (true) {
            pair<int, int> p = *range.begin();
            range.erase(p);

            if (++indices[p.second] == nums[p.second].size())
                break;
            range.insert({nums[p.second][indices[p.second]], p.second});

            int left = (*range.begin()).first;
            int right = (*range.rbegin()).first;
            if (right - left < min_range) {
                min_range = right - left;
                ans[0] = left;
                ans[1] = right;
            }
        }

        return ans;
    }
};
