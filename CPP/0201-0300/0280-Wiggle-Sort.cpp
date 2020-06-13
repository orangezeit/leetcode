class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> ans(nums.size());
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size() - 1;
        int k = 0;
        bool flag = true;

        while (i <= j) {
            if (flag) {
                ans[k++] = nums[i++];
            } else {
                ans[k++] = nums[j--];
            }
            flag = !flag;
        }

        nums = ans;
    }
};
