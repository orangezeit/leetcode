class Solution {
public:
    int minOperations(int n) {
        int s(0);
        for (int i = 1; i <= 2 * n - 1; i += 2) s += i;
        s /= n;
        int ans(0);
        for (int i = 1; i < s; i += 2) ans += s - i;
        return ans;
    }
};
