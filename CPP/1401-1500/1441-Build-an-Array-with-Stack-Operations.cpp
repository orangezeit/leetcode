class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int k(0);
        vector<string> ans;
        for (int i = 1; i <= n; ++i) {
            if (k == target.size()) break;
            ans.push_back("Push");
            if (i == target[k]) {
                k++;
            } else {
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};
