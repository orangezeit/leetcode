class Solution {
public:
    int checkRecord(int n) {
        if (n == 1) return 3;
        // atd = pl(n) + n * pl(n-1)
        vector<vector<long>> record(n + 1, vector<long>(2));
        int mod(1e9 + 7);

        record[0][0] = record[0][1] = 0;
        record[1][0] = record[1][1] = 1;
        record[2][0] = record[2][1] = 2;

        for (int i = 3; i <= n; ++i) {
            record[i][0] = record[i - 1][0] + record[i - 1][1];
            record[i][1] = record[i - 1][0] + record[i - 2][0];
            record[i][0] %= mod;
            record[i][1] %= mod;
        }

        int ans(0);
        ans += (record[n][0] + record[n][1]) % mod;
        ans %= mod;

        for (int i = 0; i < n; ++i) {
            long left = i ? (record[i][0] + record[i][1]) : 1;
            long right = i == n - 1 ? 1 : (record[n - i - 1][0] + record[n - i - 1][1]);
            ans += (left * right) % mod;
            ans %= mod;
        }
        return ans;
    }
};
