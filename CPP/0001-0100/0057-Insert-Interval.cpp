class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& invs, vector<int>& ni) {
        // Time Complexity: O(N)
        // Space Complexity: O(N)

        vector<vector<int>> ans;
        for (int i = 0; i < invs.size(); ++i) {
            if (ni[1] < invs[i][0]) {
                ans.emplace_back(ni);
                ans.insert(ans.end(), invs.begin() + i, invs.end());
                return ans;
            } else if (ni[0] > invs[i][1]) {
                ans.emplace_back(invs[i]);
            } else {
                ni[0] = min(ni[0], invs[i][0]);
                ni[1] = max(ni[1], invs[i][1]);
            }
        }
        ans.emplace_back(ni);
        return ans;
    }
};
