class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.rbegin(), piles.rend());
        int n = piles.size() / 3, ans = 0;
        for (int i = 1; i <= 2 * n - 1; i += 2)
            ans += piles[i];
        return ans;
    }
};
