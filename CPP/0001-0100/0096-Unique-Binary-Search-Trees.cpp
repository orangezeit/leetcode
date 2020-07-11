class Solution {
public:
    int numTrees(int n) {
        // Time Complexity: O(N)
        // Space Complexity: O(1)
        long ans(1);
        for (int i = n + 2; i <= 2 * n; ++i)
            ans = ans * i / (i - n - 1);
        return ans / n;
    }
};
