class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for (const char& c: s)
            if (st.empty() || st.top().first != c)
                st.push({c, 1});
            else if (++st.top().second == k)
                st.pop();
        string ans;
        while (!st.empty()) {
            ans += string(st.top().second, st.top().first);
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
