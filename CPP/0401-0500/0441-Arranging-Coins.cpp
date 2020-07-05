class Solution {
public:
    int arrangeCoins(long n) {
        long x = sqrt(n * 2);
        return (x + 1) * x / 2 <= n ? x : x - 1;
    }
};
