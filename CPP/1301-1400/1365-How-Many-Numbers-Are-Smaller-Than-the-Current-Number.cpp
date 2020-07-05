class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans(nums.size());
        map<int, int> counts;
        for (const int& i: nums) counts[i]++;

        map<int, int> counts2(counts);
        auto it = counts.begin();
        while (++it != counts.end()) it->second += prev(it)->second;

        for (int i = 0; i < nums.size(); ++i)
            ans[i] = counts[nums[i]] - counts2[nums[i]];

        return ans;
    }
};
