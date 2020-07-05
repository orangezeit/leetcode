class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n = books.size();
        int dp[n];

        for (int j = 0; j < n; ++j) {
            int w(0), h(0);
            dp[j] = INT_MAX;
            for (int i = j; i >= 0; --i) {
                if ((w += books[i][0]) > shelf_width) break;
                h = max(h, books[i][1]);
                dp[j] = min(dp[j], (i ? dp[i-1] : 0) + h);
            }
        }

        return dp[n-1];
    }
};
