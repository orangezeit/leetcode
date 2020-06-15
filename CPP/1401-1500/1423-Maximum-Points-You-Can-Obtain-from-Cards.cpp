class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        // Time Complexity: O(k)
        // Space Complexity: O(1)

        int n(cp.size()), left(0), right(0);

        for (int i = 0; i < k; ++i) left += cp[i];

        int ans(left);

        for (int i = 0; i < k; ++i) {
            left -= cp[k - i - 1];
            right += cp[n - i - 1];
            ans = max(ans, left + right);
        }

        return ans;
    }
};
