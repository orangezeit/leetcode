class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> st;

        for (int i = 0; i < S.length(); ++i)
            st.empty() ? st.push(S[i]) : st.top() == S[i] ? st.pop() : st.push(S[i]);
        S = S.substr(0, st.size());

        int k = st.size();

        while (k) {
            S[--k] = st.top();
            st.pop();
        }

        return S;
    }
};
