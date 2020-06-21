class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // two pointer
        int product = 1;
        int j = 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); ++i) {
            product *= nums[i];
            while (product >= k) {
                product /= nums[j++];
                if (j > i) break;
            }

            ans += i - j + 1;
        }
        return ans;
    }
};
