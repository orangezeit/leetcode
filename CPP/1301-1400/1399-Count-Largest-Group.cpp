class Solution {
public:
    int countLargestGroup(int n) {
        int ds[36] = {};
        int mc(0), ans(0);
        for (int i = 1; i <= n; ++i) {
            int x(i), s(0);
            while (x) {
                s += x % 10;
                x /= 10;
            }
            mc = max(mc, ++ds[s-1]);
        }
        for (int i = 0; i < 36; ++i)
            if (ds[i] == mc)
                ans++;
        return ans;
    }
};
