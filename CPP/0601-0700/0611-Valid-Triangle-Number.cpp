class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt(0);
        for (int i = 0; i < nums.size(); i++) {
            int lo(0), hi(i - 1);
            while(lo < hi)
                nums[lo] + nums[hi] > nums[i] ? cnt += hi-- - lo : lo++;
        }
        return cnt;
    }
};
