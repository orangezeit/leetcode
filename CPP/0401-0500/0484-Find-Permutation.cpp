class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> ans(s.length() + 1);
        stack<int> st;
        int j(0);
        for (int i = 1; i <= s.length(); ++i) {
            st.push(i);
            if (s[i-1] == 'I')
                while (!st.empty()) {
                    ans[j++] = st.top();
                    st.pop();
                }
        }
        st.push(s.length() + 1);
        while (!st.empty()) {
            ans[j++] = st.top();
            st.pop();
        }
        return ans;
    }
};
