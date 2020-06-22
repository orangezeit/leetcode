class Solution {
public:
    int dp[100][100][100] = {};
    int search(int l, int r, int k, const vector<int>& boxes) {
        if (l > r) return 0;
        if (dp[l][r][k]) return dp[l][r][k];
        while (l < r && boxes[r-1] == boxes[r]) {
            r--;
            k++;
        }
        dp[l][r][k] = search(l, r-1, 0, boxes) + (k + 1) * (k + 1);
        for (int i = l; i < r; ++i) {
            if (boxes[i] == boxes[r])
                dp[l][r][k] = max(dp[l][r][k], search(i+1, r-1, 0, boxes) + search(l, i, k + 1, boxes));
        }
        return dp[l][r][k];
    }

    int removeBoxes(vector<int>& boxes) {
        return search(0, boxes.size() - 1, 0, boxes);
    }
};
