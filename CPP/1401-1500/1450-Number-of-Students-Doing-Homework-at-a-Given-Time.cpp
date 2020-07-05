class Solution {
public:
    int busyStudent(vector<int>& st, vector<int>& et, int q) {
        int n = st.size(), c(0);
        for (int i = 0; i < n; ++i) {
            if (st[i] <= q && q <= et[i]) c++;
        }
        return c;
    }
};
