class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i(0), ans(0), c(0);
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] % 2) c++;
            if (k == c) {
                int t1(i), t2(j);
                while (nums[i++] % 2 == 0) {};
                while (++j < nums.size() && nums[j] % 2 == 0) {}
                ans += (i - t1) * ((j--) - t2);
                c--;
            }
        }

        return ans;
    }
};
