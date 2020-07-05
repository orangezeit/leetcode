class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        int loc(0);
        vector<int> ans = {0};
        for (int i = 0; i < n; ++i) {
            ans.insert(ans.end(), ans.rbegin(), ans.rend());
            for (int j = ans.size() / 2; j < ans.size(); ++j) {
                ans[j] += (1 << i);
                if (ans[j] == start) loc = j;
            }
        }
        rotate(ans.begin(), ans.begin() + loc, ans.end());
        return ans;
    }
};
