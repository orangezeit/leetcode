class Solution {
public:
    string convert(string s, int numRows) {
        // Time Complexity: O(N)
        // Space Complexity: O(N)
        if (numRows == 1) return s;

        string s2, strs[numRows];

        int k(0);
        bool inverse(false);

        for (int i = 0; i < s.length(); ++i)
            if (inverse) {
                strs[k--] += s[i];
                if (k == -1) {
                    k += 2;
                    inverse = false;
                }
            } else {
                strs[k++] += s[i];
                if (k == numRows) {
                    k -= 2;
                    inverse = true;
                }
            }

        for (int i = 0; i < numRows; ++i) s2 += strs[i];

        return s2;
    }
};
