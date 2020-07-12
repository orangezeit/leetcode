class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int k = -1;
        for (int i = nums.size()-1; i >= 1; --i) {
            if (nums[i-1] > nums[i]) {
                k = i-1;
            } else if (k != -1) {
                return k;
            }
        }

        if (k == -1) {
            return nums.size()-1;
        } else {
            return 0;
        }
    }
};
