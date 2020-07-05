class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }

        int i = 0;
        int j = nums.size()-1;

        while (j - i > 1) {
            if (nums[(i+j)/2] == target) {
                return (i+j)/2;
            } else if (nums[(i+j)/2] > target) {
                if (nums[(i+j)/2] < nums[j] || target >= nums[i]) {
                    j = (i+j)/2;
                } else {
                    i = (i+j)/2;
                }
            } else {
                if (nums[(i+j)/2] > nums[i] || target <= nums[j]) {
                    i = (i+j)/2;
                } else {
                    j = (i+j)/2;
                }
            }
            //cout << i << " " << j << endl;
        }

        if (nums[i] == target) {
            return i;
        } else if (nums[j] == target) {
            return j;
        } else {
            return -1;
        }
    }
};
