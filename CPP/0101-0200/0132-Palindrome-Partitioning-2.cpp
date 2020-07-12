class Solution {
public:
    int minCut(string s) {
        // Time Complexity: O(N^2)
        // Space Complexity: O(N^2)
        int n(s.length()), cuts[n] = {};
        bool pld[n][n] = {};

        for (int i = 0; i < n; ++i) {
            int mc = i;
            for (int j = 0; j <= i; ++j)
                if (s[i] == s[j] && (j + 1 > i - 1 || pld[j + 1][i - 1])) {
                    pld[j][i] = true;
                    minCut = min(minCut, j ? 1 + cuts[j - 1] : 0);
                }
            cuts[i] = minCut;
        }

        return cuts[n - 1];
    }
};
