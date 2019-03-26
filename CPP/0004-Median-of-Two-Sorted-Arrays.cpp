    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() && nums2.empty()) {
            return 0.0;
        } else if (nums1.empty()) {
            return nums2.size() % 2 ? nums2[nums2.size() / 2] * 1.0 : (nums2[nums2.size() / 2 - 1] + nums2[nums2.size() / 2]) / 2.0;
        } else if (nums2.empty()) {
            return nums1.size() % 2 ? nums1[nums1.size() / 2] * 1.0 : (nums1[nums1.size() / 2 - 1] + nums1[nums1.size() / 2]) / 2.0;
        }
        
        if (nums1.size() > nums2.size() || (nums1.size() == nums2.size() && nums1[0] > nums2[0])) {
            nums1.swap(nums2);
        }
        
        int n = (nums1.size() + nums2.size()) / 2 + 1;
        int i(0), j(0), id(0);
        int medians[2] = {0, 0};
        
        while (n--) {
            nums1[i] <= nums2[j] && i < nums1.size() ? medians[id] = nums1[i++] : medians[id] = nums2[j++];
            id = !id;
        }
        
        return (nums1.size() + nums2.size()) % 2 ? max(medians[0], medians[1]) * 1.0 : (medians[0] + medians[1]) / 2.0;
    }
