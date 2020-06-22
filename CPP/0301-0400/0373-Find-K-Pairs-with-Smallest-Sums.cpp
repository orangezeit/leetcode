class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        k = min(k, n1 * n2);

        vector<pair<int, int>> ans(k);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> record;

        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < nums2.size(); ++j) {
                record.push({nums1[i] + nums2[j], {nums1[i], nums2[j]}});
            }
        }

        for (int i = 0; i < k; ++i) {
            ans[i] = record.top().second;
            record.pop();
        }

        return ans;
    }
};
