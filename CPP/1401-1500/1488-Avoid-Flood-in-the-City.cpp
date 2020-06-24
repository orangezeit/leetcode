class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n(rains.size());
        set<int> suns; // indices of sunny days
        unordered_map<int, int> lakes; // last rainy day for each lake
        vector<int> ans(n, -1);

        for (int i = 0; i < n; ++i) {
            if (rains[i]) {
                if (lakes.count(rains[i])) {
                    auto it = suns.lower_bound(lakes[rains[i]] + 1);
                    if (it == suns.end()) return {};
                    ans[*it] = rains[i];
                    suns.erase(it);
                }
                lakes[rains[i]] = i;
            } else {
                suns.insert(i);
                ans[i] = 1;
            }
        }

        return ans;
    }
};
