class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left(1), right(m * n + 1); // left open, right closed

        auto lex = [&](int x) {
            int s(0);
            for (int i = 1; i <= m; ++i) {
                if (!(x / i) || s >= k) break;
                s += min(n, x / i);
            }
            return s;
        };

        while (left < right) {
            int mid = (left + right) / 2;
            lex(mid) >= k ? right = mid : left = mid + 1;
        }

        return left;
    }
};
