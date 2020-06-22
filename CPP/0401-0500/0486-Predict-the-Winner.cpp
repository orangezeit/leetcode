class Solution {
public:
    int n;
    unordered_map<int, int> s;
    int traverse(const vector<int>& nums, int i, int j, bool player) {
        if (s.find(i * n + j) != s.end()) return s[i * n + j];
        if (j - i == 1) {
            s[i * n + j] = player ? nums[i] : -nums[i];
        } else {
            int s1 = traverse(nums, i+1, j, !player) ;
            player ? s1 += nums[i] : s1 -= nums[i];
            int s2 = traverse(nums, i, j-1, !player);
            player ? s2 += nums[j-1] : s2 -= nums[j-1];
            s[i * n + j] = player^(s1 < s2) ? s1 : s2;
        }
        return s[i * n + j];
    }
    bool PredictTheWinner(vector<int>& nums) {
        n = nums.size();
        return traverse(nums, 0, n, true) >= 0;
    }
};
