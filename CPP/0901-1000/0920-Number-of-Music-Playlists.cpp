class Solution {
public:
    long factorial(int n, const int& mod) {
        return n ? n * factorial(n - 1, mod) % mod : 1;
    }
    int numMusicPlaylists(int N, int L, int K) {
        long dp[N+1][L+1];
        int mod(1e9+7);

        for (int i = K + 1; i <= N; ++i)
            for (int j = i; j <= L; ++j) {
                if (i == j || i == K + 1)
                    dp[i][j] = factorial(i, mod);
                else
                    dp[i][j] = (dp[i-1][j-1] * i + dp[i][j-1] * (i - K)) % mod;
            }
        return dp[N][L];
    }
};
