class Solution {
public:
    int findKthNumber(int n, int k) {
        //return 1;
        int c = 1;
        while (k > 1) {
            int g = findGap(c, n);
            if (g < k) {
                k -= g;
                c++;
            } else {
                k--;
                c *= 10;
            }
        }
        return c;
    }

    int findGap(long x, long n) {
        long y(x + 1), g(0);
        while (x <= n) {
            g += min(n + 1, y) - x;
            x *= 10;
            y *= 10;
        }
        return g;
    }
};
