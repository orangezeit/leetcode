class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        unordered_map<int, vector<pair<int, int>>> ps;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ps[nums[i] + nums[j]].push_back({i, j});
            }
        }
        set<vector<int>> ans;
        for (const auto& [k1, v1]: ps) {
            if (ps.count(target - k1)) {
                for (const auto& [x1, y1]: v1) {
                    for (const auto& [x2, y2]: ps[target - k1]) {
                        if (x1 != x2 && x1 != y2 && y1 != x2 && y1 != y2) {
                            vector<int> res({nums[x1], nums[x2], nums[y1], nums[y2]});
                            sort(res.begin(), res.end());
                            ans.insert(res);
                        }
                    }
                }
            }
        }
        
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
