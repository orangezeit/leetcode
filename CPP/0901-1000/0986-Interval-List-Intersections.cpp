class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        map<int, int> record;

        for (const vector<int>& a: A) {
            record[a[0]]++;
            record[a[1]]--;
        }

        for (const vector<int>& b: B) {
            record[b[0]]++;
            record[b[1]]--;
        }

        vector<vector<int>> ans;
        int s = 0;

        for (const auto& [k, v]: record) {
            s += v;
            if (s == 2) {
                ans.push_back({k, -1});
            } else if (v == 0) {
                ans.push_back({k, k});
            } else if (!ans.empty() && ans.back()[1] == -1) {
                ans.back()[1] = k;
            }
        }
        return ans;
    }
};
