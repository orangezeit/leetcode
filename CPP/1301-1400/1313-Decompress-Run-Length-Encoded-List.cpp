class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int n(0), c(0);
        for (int i = 0; i < nums.size(); i += 2) n += nums[i];
        vector<int> ans(n);
        for (int i = 0; i < nums.size(); i += 2) {
            for (int k = 0; k < nums[i]; ++k)
                ans[c++] = nums[i+1];
        }
        return ans;
    }
};
