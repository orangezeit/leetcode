class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Time Complexity: O(N)
        // Space Complexity: O(N)
        unordered_set<char> st;
        int ans(0);

        for (int i = 0, j = 0; j < s.length(); ++j) {
            if (st.count(s[j]))
                while (s[i++] != s[j])
                    st.erase(s[i - 1]);
            else
                st.insert(s[j]);
            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};
