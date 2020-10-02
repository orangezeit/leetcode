class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        vector<int> s;
        int ans(INT_MAX);
        for (int i: arr) {
            vector<int> t{i};
            for (int j: s) {
                int x = i & j;
                auto iter = lower_bound(t.begin(), t.end(), x);
                if (iter == t.end() || *iter == x) continue;
                t.insert(iter, x);
            }
            auto it = lower_bound(t.begin(), t.end(), target);
            if (it != t.end()) ans = min(ans, *it - target);
            if (it != t.begin()) ans = min(ans, target - *prev(it));
            swap(s, t);
        }
        return ans;
    }
};
