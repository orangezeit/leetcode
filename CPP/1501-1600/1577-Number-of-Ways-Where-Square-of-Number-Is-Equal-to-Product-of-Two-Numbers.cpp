class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> roots1, roots2;
        int n1(nums1.size()), n2(nums2.size()), ans(0);
        for (const int& i: nums1) roots1[i]++;
        for (const int& i: nums2) roots2[i]++;
        for (int i = 0; i < n2; ++i) {
            for (int j = i + 1; j < n2; ++j) {
                long p = (long) nums2[i] * nums2[j];
                long r = sqrt(p);
                if (r * r != p || !roots1.count(r)) continue;
                ans += roots1[r];
            }
        }
        for (int i = 0; i < n1; ++i) {
            for (int j = i + 1; j < n1; ++j) {
                long p = (long) nums1[i] * nums1[j];
                long r = sqrt(p);
                if (r * r != p || !roots2.count(r)) continue;
                ans += roots2[r];
            }
        }
        return ans;
    }
};
