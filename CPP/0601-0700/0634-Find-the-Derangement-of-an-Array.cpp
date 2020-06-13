class Solution {
public:
    int findDerangement(int n) {

        long f[3] = {};
        f[0] = 1;
        if (n > 1) f[2] = 1;

        for (int i = 3; i <= n; ++i) {
            f[i % 3] = ((i - 1) * (f[(i-1) % 3] + f[(i-2) % 3])) % 1000000007;
        }
        return f[n % 3];
    }
};
