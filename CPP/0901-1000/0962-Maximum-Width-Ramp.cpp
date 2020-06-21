class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        // build a strictly decreasing stack
        stack<int> st;
        int w(0);
        for (int i = 0; i < A.size(); ++i) {
            if (st.empty() || A[st.top()] > A[i])
                st.push(i);
        }
        for (int i = A.size() - 1; i >= 0; --i) {
            while (!st.empty() && A[st.top()] <= A[i]) {
                w = max(w, i - st.top());
                st.pop();
            }
        }

        return w;
    }
};
