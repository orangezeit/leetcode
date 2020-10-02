class Solution {
public:
    int numWays(string s) {
        // Time Complexity: O(N)
        // Space Complexity: O(1)
        long s1(0), n(s.length()), mod(1000000007);
        for (const char& c: s) if (c == '1') s1++;
        if (s1 == 0) return (n - 1) * (n - 2) / 2 % mod;
        if (s1 % 3) return 0;
        long p1(0), p2(0), s2(0);
        for (const char& c: s) {
            if (c == '1') s2++;
            if (s2 == s1 / 3) p1++;
            else if (s2 == s1 / 3 * 2) p2++;
        }
        return p1 * p2 % mod;
    }
};
