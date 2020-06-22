class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for (const char& c: num) {
            while (!st.empty() && st.top() > c && k && k--)
                st.pop();
            st.push(c);
        }

        while (k--) st.pop();
        string ans;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        while (!ans.empty() && ans.back() == '0')
            ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans.empty() ? "0" : ans;
    }
};
