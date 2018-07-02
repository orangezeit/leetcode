private:
    vector<vector<int>> subs;
public:
    void subsetHelper(vector<int> nums, vector<int> sub, int k) {
        if (nums.size() == k) {
            subs.push_back(sub);
        } else {
            subsetHelper(nums, sub, k+1);
            sub.push_back(nums[k]);
            subsetHelper(nums, sub, k+1);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sub;
        subsetHelper(nums, sub, 0);
        return subs;
    }
