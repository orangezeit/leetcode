class Solution {
public:
    int numWays(int n, int k) {
        if (n < 2) return n * k;
        int p1(k), p2(k * k);
        for (int i = 2; i < n; ++i) {
            int t = p1;
            p1 = p2;
            p2 = (k - 1) * (t + p2);
        }
        return p2;
    }
};
