class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i = 0;
        int j = nums.size();

        while (i < j && j != 1) {
            //cout << i << ' ' << j << endl;
            int k = (i+j)/2;
            if (nums[k] != nums[k-1] && nums[k] != nums[k+1]) {
                return nums[k];
            } else if ((nums[k] == nums[k-1] && k % 2 == 1) || (nums[k] == nums[k+1] && k % 2 == 0)) {
                i = k+1;
            } else {
                j = k;
            }

        }

        return nums[i];
    }
};
