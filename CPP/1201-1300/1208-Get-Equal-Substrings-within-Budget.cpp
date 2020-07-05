class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> costs(s.length());
        for (int i = 0; i < s.length(); ++i)
            costs[i] = abs(s[i] - t[i]);
        int k = 0;
        int c = 0;
        int len(0);

        for (int i = 1; i <= s.length(); ++i) {
            c += costs[i - 1];
            while (c > maxCost)
                c -= costs[k++];
            len = max(len, i - k);
        }

        return len;
    }
};
