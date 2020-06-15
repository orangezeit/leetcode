class Solution {
public:
    int numOfWays(int n) {
        long a(6), b(6), mod(1000000007);
        for (int i = 0; i < n - 1; ++i) {
            a = 2 * (a + b) % mod;
            b = (a + b) % mod;
        }
        return (a + b) % mod;
    }
};
