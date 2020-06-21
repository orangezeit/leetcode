class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        //cout << compare(18.0/4,18.0/4) << endl;
        int k(A.size());
        int s(0);
        for (int i: A) s += i;
        double target = (double) s / k;

        vector<vector<int>> dp(s + 1, vector<int>(k + 1));
        dp[0][0] = 1;
        for (int i = 0; i < k; ++i) {
            for (int x = s; x >= A[i]; --x) {
                for (int n = i + 1; n >= 1; --n) {
                    if (dp[x - A[i]][n - 1]) {
                        dp[x][n] = dp[x - A[i]][n - 1];
                        if (n != k && (double) x / n == target)
                            return true;
                    }
                }
            }
        }

        return false;
    }
};
