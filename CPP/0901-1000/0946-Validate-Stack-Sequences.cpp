class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i(0), j(0);

        while (i < pushed.size())
            if (pushed[i] == popped[j]) {
                i++;
                j++;
            } else if (!st.empty() && st.top() == popped[j]) {
                st.pop();
                j++;
            } else
                st.push(pushed[i++]);

        while (!st.empty())
            if (st.top() == popped[j++])
                st.pop();
            else
                return false;

        return true;
    }
};
