    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) {
            return;
        } else if (m == 0) {
            nums1 = nums2;
            return;
        }
        
        int i = m + n - 1;
        m--;
        n--;
        
        while (n >= 0 && m >= 0) {
            nums1[m] <= nums2[n] ? nums1[i--] = nums2[n--] : nums1[i--] = nums1[m--];
        }

        while (n >= 0) {
            nums1[i--] = nums2[n--];
        }
    }
