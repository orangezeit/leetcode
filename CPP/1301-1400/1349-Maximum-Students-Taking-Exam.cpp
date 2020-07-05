class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m(seats.size()), n(seats[0].size());
        int s[m + 1] = {};
        int dp[m + 1][1 << n] = {};

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (seats[i][j] == '.')
                    s[i + 1] |= (1 << j);

        for (int i = 0; i < m; ++i)
            for (int l = s[i]; ; l = (l - 1) & s[i]) {
                for (int c = s[i + 1]; ; c = (c - 1) & s[i + 1]) {
                    if (!(c & (c >> 1)) && !(l & (c >> 1)) && !(c & (l >> 1)))
                        dp[i + 1][c] = max(dp[i + 1][c], dp[i][l] + __builtin_popcount(c));
                    if (c == 0) break;
                }
                if (l == 0) break;
            }
        return *max_element(dp[m], dp[m] + (1 << n));
    }
};
