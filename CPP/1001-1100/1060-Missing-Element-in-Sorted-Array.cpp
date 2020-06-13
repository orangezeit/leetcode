class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int inside = nums.back() - nums[0] - nums.size() + 1;
        if (k > inside) return nums.back() + k - inside;

        int left = 0;
        int right = nums.size() - 1;

        while (right - left > 1) {
            int mid = (left + right) / 2;

            int d = nums[mid] - nums[left] - mid + left;
            if (d >= k) {
                right = mid;
            } else {
                left = mid;
                k -= d;
            }
        }
        //cout << left << " " << right << " " << k << endl;
        return nums[left] + k;
    }
};
