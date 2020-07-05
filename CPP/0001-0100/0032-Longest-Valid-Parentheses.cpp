class Solution {
public:
    int longestValidParentheses(string s) {
        // Time Complexity: O(N)
        // Space Complexity: O(N)
        stack<int> st;
        for (int i = 0; i < s.length(); ++i) {
            if (!st.empty() && s[st.top()] == '(' && s[i] == ')') st.pop();
            else st.push(i);
        }
        int ans(0), last(s.length());
        while (!st.empty()) {
            ans = max(ans, last - st.top() - 1);
            last = st.top();
            st.pop();
        };
        return max(ans, last);
    }
};
