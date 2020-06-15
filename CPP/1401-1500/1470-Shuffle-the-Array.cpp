class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> na(2 * n);
        for (int i = 0; i < 2 * n; i += 2) {
            na[i] = nums[i / 2];
            na[i + 1] = nums[i / 2 + n];
        }
        return na;
    }
};
