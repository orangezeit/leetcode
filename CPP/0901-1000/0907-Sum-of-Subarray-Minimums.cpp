class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {

        // next smaller elements -> monotone stack (store indices)
        // include greater and equal elements
        // prev smaller or equal elements -> monotone stack (store indices)
        // include only greater elements to avoid repeated counting

        vector<int> nextSmaller(A.size(), A.size()), prevSmaller(A.size(), -1);
        stack<int> st;
        long ans(0);

        for (int i = 0; i < A.size(); ++i) {
            while (!st.empty() && A[st.top()] > A[i]) {
                nextSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = A.size() - 1; i >= 0; --i) {
            while (!st.empty() && A[st.top()] >= A[i]) {
                prevSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        for (int i = 0; i < A.size(); ++i) {
            ans += (i - prevSmaller[i]) * (nextSmaller[i] - i) * A[i];
            ans %= 1000000007;
        }
        return ans;
    }
};
