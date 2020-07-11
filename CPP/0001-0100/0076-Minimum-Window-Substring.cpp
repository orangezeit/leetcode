class Solution {
public:
    string minWindow(string s, string t) {
        // Time Complexity: O(N)
        // Space Complexity: O(N)
        vector<int> mp(128);
        for (const char& c: t) mt[c]++;
        int cnt(t.length()), left(0), right(0), d(INT_MAX), h(0);
        while(right < s.length()) {
            if (mp[s[right++]]-- > 0) cnt--; //in t
            while (!cnt) {
                if (right - left < d)  d = right - (h = left);
                if (!(mp[s[left++]]++)) cnt++;
            }
        }
        return d == INT_MAX ? "" : s.substr(h, d);
    }
};
