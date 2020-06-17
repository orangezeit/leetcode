class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int n(stones.size());
        int mx = max(stones[n-2] - stones[0], stones[n-1] - stones[1]) - n + 2;

        int mn(INT_MAX);
        for (int i = 0; i < n; ++i) {
            int j(i);
            while (j < n && stones[j] - stones[i] + 1 < n) j++;
            if (j == n) break;
            int temp = stones[j] - stones[i] + 1 == n ? n - j + i - 1 : j - i == n - 1 ? 2 : n - j + i;
            mn = min(mn, temp);
        }
        return {mn, mx};
    }
};
