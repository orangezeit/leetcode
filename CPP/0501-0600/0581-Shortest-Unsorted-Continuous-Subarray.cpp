class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> nums_copy = nums;
        int left(-1), right(-1);
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != nums_copy[i]) {
                left = i;
                break;
            }
        }

        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] != nums_copy[i]) {
                right = i;
                break;
            }
        }

        return left == -1 ? 0 : right - left + 1;
    }
};
