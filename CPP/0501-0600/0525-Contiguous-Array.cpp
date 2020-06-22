class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, pair<int, int>> m({{0, {0, 0}}});
        int k(0), ans(0);
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] ? k++ : k--;
            if (m.count(k))
                m[k].second = i + 1;
            else
                m[k] = {i + 1, 0};
        }
        for (const auto& [k, v]: m)
            ans = max(ans, v.second - v.first);
        return ans;
    }
};
