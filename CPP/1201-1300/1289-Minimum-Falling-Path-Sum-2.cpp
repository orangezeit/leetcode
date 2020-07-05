class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        for (int i = 1; i < arr.size(); ++i) {
            for (int j = 0; j < arr[0].size(); ++j) {
                int ans = INT_MAX;
                for (int k = 0; k < arr[0].size(); ++k) {
                    if (j != k)
                        ans = min(ans, arr[i][j] + arr[i-1][k]);
                }
                arr[i][j] = ans;
            }
        }
        int ans(INT_MAX);
        for (int i = 0; i < arr[0].size(); ++i) {
            ans = min(ans, arr.back()[i]);
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
