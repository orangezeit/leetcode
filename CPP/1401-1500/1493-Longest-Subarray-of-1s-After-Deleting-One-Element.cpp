class Solution {
public:
  int longestSubarray(vector<int>& nums) {
    const int n = nums.size();
    int ans = 0;
    int sum = 0;
    for (int l = 0, r = 0; r < n; ++r) {
      sum += nums[r];
      while (l < r && sum < r - l)
        sum -= nums[l++];
      ans = max(ans, r - l);
    }
    return ans;
  }
};
