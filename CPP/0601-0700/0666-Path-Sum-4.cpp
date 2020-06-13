class Solution {
public:
    int pathSum(vector<int>& nums) {
        int n(nums.size());
        unordered_map<int, int> levels, sums;
        for (int i = n - 1; i >= 0; --i) {
            int d(nums[i] / 100), p(nums[i] / 10 % 10), v(nums[i] % 10);
            levels[100 * d + p] = max(1, levels[100 * (d + 1) + 2 * p - 1] +
                                         levels[100 * (d + 1) + 2 * p]);
            sums[100 * d + p] = levels[100 * d + p] * v + sums[100 * (d + 1) + 2 * p - 1] +
                                                          sums[100 * (d + 1) + 2 * p];
            //cout << d << p << v << endl;
        }
        return sums[101];
    }
};
