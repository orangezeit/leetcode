class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        map<int, int> invs;

        // 0  1  2 3  4  5  6  7

        // 1 -1 -1 1 -1 +1 +1 -1
        // 1  0 -1 0 -1  0  1  0
        for (const vector<int>& itv: intervals) {
            invs[itv[0]]++;
            invs[itv[1]]--;
        }

        invs[toBeRemoved[0]]--;
        invs[toBeRemoved[1]]++;
        int a(0);
        vector<vector<int>> ans;

        for (const auto& p: invs) {
            a += p.second;
            if (a > 0) ans.push_back({p.first, -1});
            else if (!ans.empty() && ans.back()[1] == -1) ans.back()[1] = p.first;
        }

        return ans;
    }
};
