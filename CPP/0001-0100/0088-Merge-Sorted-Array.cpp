class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Time Complexity: O(M + N)
        // Space Complexity: O(1)
        int x(m-- + n--);
        while (n >= 0)
            nums1[--x] = m < 0 || nums1[m] <= nums2[n] ? nums2[n--] : nums1[m--];
    }
};
