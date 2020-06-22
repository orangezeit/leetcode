class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        if (!k) return {};
        vector<double> ans(nums.size() - k + 1);
        vector<int> window(nums.begin(), nums.begin() + k);
        sort(window.begin(), window.end());
        ans[0] = window[k/2] / 2.0 + window[(k-1)/2] / 2.0;
        for (int i = 0; i < nums.size() - k; ++i) {
            window.push_back(nums[k + i]);
            auto it = --window.end();
            rotate(upper_bound(window.begin(), it, *it), it, it + 1);
            window.erase(lower_bound(window.begin(), window.end(), nums[i]));
            ans[i + 1] = window[k/2] / 2.0 + window[(k-1)/2] / 2.0;
        }
        //for (int i: window) cout << i << " ";
        return ans;
    }
};
