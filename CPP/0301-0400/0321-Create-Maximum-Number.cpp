class Solution {
public:
    const bool compareArray(const vector<int>& nums1, int i, const vector<int> nums2, int j) {
        while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
            i++;
            j++;
        }
        return j == nums2.size() || (i < nums1.size() && nums1[i] > nums2[j]);
    }
    const vector<int> maxArray(const vector<int>& nums, const int& k) {
        stack<int> st;
        vector<int> ans(k);
        for (int i = 0; i < nums.size(); ++i) {
            while (!st.empty() && st.size() + nums.size() - i > k && st.top() < nums[i]) st.pop();
            if (st.size() < k) st.push(nums[i]);
        }
        for (int i = k - 1; i >= 0; --i) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }

    const vector<int> mergeArray(const vector<int>& nums1, const vector<int>& nums2) {
        vector<int> nums(nums1.size() + nums2.size());
        int i(0), j(0), k(0);
        while (k < nums.size())
            nums[k++] = compareArray(nums1, i, nums2, j) ? nums1[i++] : nums2[j++];
        return nums;
    }
    //bool compareArray(const vector<int>)
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans(k);
        for (int i = 0; i <= min(k, (int)nums1.size()); ++i) {
            if (k - i > nums2.size()) continue;
            vector<int> temp = mergeArray(maxArray(nums1, i), maxArray(nums2, k - i));
            if (compareArray(temp,0, ans, 0)) swap(ans, temp);
        }
        return ans;
    }
};
