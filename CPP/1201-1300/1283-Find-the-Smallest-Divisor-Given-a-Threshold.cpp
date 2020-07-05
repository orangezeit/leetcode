class Solution {
public:
    int divide(const vector<int>& nums, int x) {
        int s(0);

        for (const int i: nums) {
            s += ceil((double)i / x);
        }

        return s;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {

        int left(1), right(1);
        for (int i: nums) right = max(right, i);

        while (right - left > 1) {
            int mid = (left + right) / 2;
            if (divide(nums, mid) <= threshold) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return divide(nums, left) <= threshold ? left : right;
    }
};
