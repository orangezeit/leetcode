class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        while (label) {
            ans.push_back(label);
            label /= 2;
        }
        reverse(ans.begin(), ans.end());
        for (int i = ans.size() - 2; i >= 0; i -= 2)
            ans[i] = 3 * (1 << i) - 1 - ans[i];
        return ans;
    }
};
