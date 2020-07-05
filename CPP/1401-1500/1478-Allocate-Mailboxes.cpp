class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(), houses.end());
        int n = houses.size();
        vector<vector<int>> base(n, vector<int>(n));

        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j) {
                int x(i), y(j);
                while (x < y)
                    base[i][j] += houses[y--] - houses[x++];
            }

        vector<int> dp(base[0].begin(), base[0].end());

        for (int x = 2; x <= k; ++x) {
            vector<int> temp(n, 1e9);
            for (int j = 1; j < n; ++j) {
                for (int d = 0; d < j; ++d) {
                    temp[j] = min(temp[j], dp[d] + base[d + 1][j]);
                }
            }
            swap(temp, dp);
        }

        return dp[n - 1];
    }
};
