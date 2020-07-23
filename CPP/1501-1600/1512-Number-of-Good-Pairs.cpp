class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        // Time Complexity: O(N)
        // Space Complexity: O(N)
        vector<int> cnts(101);
        int ans(0);
        for (const int& n: nums)
            ans += cnts[n]++;
        return ans;
    }
};
