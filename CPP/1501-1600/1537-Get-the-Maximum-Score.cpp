class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m1, m2;
        int n1(nums1.size()), n2(nums2.size());
        for (int i = 0, j = 0; i < n1 && j < n2; ++i) {
            while (j < n2 && nums1[i] > nums2[j]) j++;
            if (j < n2 && nums1[i] == nums2[j]) {
                m1[i] = j;
                m2[j] = i;
                j++;
            }
        }
        vector<long> dp1(n1 + 1), dp2(n2 + 1);
        int k1(0), k2(0);
        while (k1 < n1 || k2 < n2) {
            while (k1 < n1) {
                dp1[k1 + 1] = dp1[k1] + nums1[k1];
                if (m1.count(k1)) break;
                k1++;
            }
            while (k2 < n2) {
                dp2[k2 + 1] = dp2[k2] + nums2[k2];
                if (m2.count(k2)) break;
                k2++;
            }
            if (m1.count(k1) && m2.count(k2)) {
                dp1[k1 + 1] = dp2[k2 + 1] = max(dp1[k1 + 1], dp2[k2 + 1]);
                k1++;
                k2++;
            }
        }
        int mod(1e9+7);
        int ans = max(dp1.back(), dp2.back()) % mod;
        return ans;
    }
};
