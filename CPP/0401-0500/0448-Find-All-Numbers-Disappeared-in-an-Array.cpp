class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> hashset(nums.begin(), nums.end()), res;

        for (int i = 1; i <= nums.size(); ++i) {
            if (hashset.find(i) == hashset.end()) {
                res.insert(i);
            }
        }

        return vector<int>(res.begin(), res.end());
    }
};
