class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n(nums.size()), sl(0), sr(0), s(0);
        vector<int> arr(n - k + 1);
        for (int i = 0; i < k; ++i) arr[0] += nums[i];
        for (int i = k; i < n; ++i) arr[i-k+1] = arr[i-k] + nums[i] - nums[i-k];

        vector<int> left(n), right(n), res(3);

        for (int i = 0; i <= n - 3 * k; ++i) {
            left[i] = arr[i] > sl ? i : left[i - 1];
            sl = max(sl, arr[i]);
        }
        for (int i = n - k; i >= 2 * k; --i) {
            right[i] = arr[i] >= sr ? i : right[i + 1];
            sr = max(sr, arr[i]);
        }

        for (int i = k; i <= n - 2 * k; ++i) {
            int t = arr[i] + arr[left[i-k]] + arr[right[i+k]];
            if (t > s) {
                res[0] = left[i-k];
                res[1] = i;
                res[2] = right[i+k];
                s = t;
            }
        }

        return res;
    }
};
