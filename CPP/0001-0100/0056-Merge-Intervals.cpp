class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Time Complexity: O(N lg N)
        // Space Complexity: O(N)
        map<int, int> m;
        for (const vector<int>& inv: intervals) {
            m[inv[0]]++;
            m[inv[1]]--;
        }
        int c(0);
        vector<vector<int>> ans;
        for (const auto&[k, v]: m) {
            c += v;
            if (c > 0 && (ans.empty() || ans.back()[1] != INT_MAX)) {
                ans.push_back({k, INT_MAX});
            } else if (c == 0) {
                if (!ans.empty() && ans.back()[1] == INT_MAX)
                    ans.back()[1] = k;
                else
                    ans.push_back({k, k});
            }
        }
        return ans;
    }
};
