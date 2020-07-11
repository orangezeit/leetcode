class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        // Time Complexity: O(MN)
        // Space Complexity: O(N)
        int m(mat.size()), n(mat[0].size()), ans(0);
        vector<int> dp(n);
        for (int i = 0; i < m; ++i) {
            stack<int> st;
            int sum(0);
            for (int j = 0; j < n; ++j) {
                dp[j] = mat[i][j] ? dp[j] + 1 : 0;
                while (!st.empty() && dp[st.top()] > dp[j]) {
                    int temp = st.top();
                    st.pop();
                    sum -= (temp - (st.empty() ? -1 : st.top())) * (dp[temp] - dp[j]);
                }
                st.push(j);
                sum += dp[j];
                ans += sum;
            }
        }
        return ans;
    }
};
