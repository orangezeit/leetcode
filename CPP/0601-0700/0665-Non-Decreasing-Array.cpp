class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int c = 0;

        for (int i = 0; i < nums.size()-1; ++i) {

            if (nums.size() >= 4 && i >= 1 && i <= nums.size() - 3) {
                if (nums[i] > nums[i+1] && nums[i+2] < nums[i] && nums[i-1] > nums[i+1]) {
                    return false;
                }
            }

            if (nums[i] > nums[i+1]) {
                ++c;
                if (c >= 2) {
                    return false;
                }
            }
        }

        return true;
    }
};
