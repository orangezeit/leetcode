class Solution {
public:
    int countOrders(int n) {
        long ans(1), m(1000000007);
        for (int i = 2; i <= n; ++i) {
            ans *= (2 * i - 1) * i;
            ans %= m;
        }
        return ans;
    }
};
