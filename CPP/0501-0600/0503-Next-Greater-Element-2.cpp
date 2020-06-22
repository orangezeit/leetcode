class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& A) {
        int n = A.size();
        stack<int> st;
        vector<int> ans(n, -1);

        for (int i = 0; i < n * 2; ++i) {
            while (!st.empty() && A[st.top()] < A[i % n]) {
                ans[st.top()] = A[i % n];
                st.pop();
            }
            st.push(i % n);
        }
        return ans;
    }
};
