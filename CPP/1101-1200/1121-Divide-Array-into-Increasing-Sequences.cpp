class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int K) {
        unordered_map<int, int> cnts;
        int maxLen(0);
        for (const int& n: nums) {
            cnts[n]++;
            maxLen = max(maxLen, cnts[n]);
        }

        return nums.size() >= K * maxLen;

    }
};
