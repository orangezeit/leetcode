class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, unordered_set<int>> record;
        vector<vector<int>> ans;

        for (int i = 0; i < groupSizes.size(); ++i) {
            record[groupSizes[i]].insert(i);
        }

        int k(0);

        for (auto p: record) {
            for (int i: p.second) {
                if (ans.empty() || ans.back().size() == k) {
                    ans.push_back(vector<int>(p.first, -1));
                    k = 0;
                }

                ans.back()[k++] = i;
            }

        }

        return ans;
    }
};
