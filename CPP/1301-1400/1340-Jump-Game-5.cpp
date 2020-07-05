class Solution {
public:
    int simulate(const vector<int>& arr, int curr, int d, int dp[]) {
        if (dp[curr]) return dp[curr];
        int res(1);
        for (int i = curr - 1; i >= max(curr - d, 0) && arr[i] < arr[curr]; --i) {
            res = max(res, simulate(arr, i, d, dp) + 1);
        }
        for (int i = curr + 1; i <= min(curr + d, int(arr.size()) - 1) && arr[i] < arr[curr]; ++i) {
            res = max(res, simulate(arr, i, d, dp) + 1);
        }
        return dp[curr] = res;
    }
    int maxJumps(vector<int>& arr, int d) {
        int dp[arr.size()] = {};
        int ans(1);
        for (int i = 0; i < arr.size(); ++i) {
            ans = max(ans, simulate(arr, i, d, dp));
        }
        return ans;
    }
};
