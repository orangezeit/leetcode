class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> rec;
        int ans(0);

        for (const int& n: arr)
            ans = max(ans, rec[n] = rec[n - difference] + 1);

        return ans;
    }
};
