class Solution {
public:
    int mergeSort(vector<int>& nums, int first, int mid, int last) {
        vector<int> temp(last - first + 1);
        int i(first), j(mid + 1), k(0), c(0);
        while (i <= mid && j <= last) {
            if ((long)nums[i] > 2 * (long)nums[j]) {
                c += (mid - i + 1);
                j++;
            } else {
                i++;
            }
        }

        i = first;
        j = mid + 1;
        while (i <= mid || j <= last)
            temp[k++] = i > mid ? nums[j++] : j > last ? nums[i++] : nums[i] < nums[j] ? nums[i++] : nums[j++];

        for (int i = first; i <= last; ++i)
            nums[i] = temp[i - first];

        return c;
    }

    int merge(vector<int>& nums, int first, int last) {
        if (first == last) return 0;
        int mid = (first + last) / 2;
        return merge(nums, first, mid) + merge(nums, mid + 1, last) + mergeSort(nums, first, mid, last);
    }

    int reversePairs(vector<int>& nums) {
        // Method 1 merge sort
        return nums.empty() ? 0 : merge(nums, 0, nums.size() - 1);
    }
};
