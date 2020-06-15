class Solution {
public:
    int maxScore(string s) {
		// Time Complexity: O(n)
		// Space Complexity: O(1)

        int l0(0), r1(0);

        for (const char& c: s)
            if (c == '1') r1++;

        s.pop_back();
        int ans(0);

        for (const char& c: s) {
            c == '0' ? l0++ : r1--;
            ans = max(ans, l0 + r1);
        }

        return ans;
    }
};
