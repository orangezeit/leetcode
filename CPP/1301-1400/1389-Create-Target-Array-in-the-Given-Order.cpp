class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> arr;
        for (int i = 0; i < nums.size(); ++i) {
            arr.insert(arr.begin() + index[i], nums[i]);
        }
        return arr;
    }
};
