class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> st, ans(arr.size());
        for (int i = 0; i < arr.size(); ++i) {
            while (!st.empty() && arr[st.back()] < arr[i])
                st.pop_back();
            st.push_back(i);
        }

        for (int i = 0, k = 0; i + 1 < arr.size(); ++i) {
            if (i == st[k]) k++;
            ans[i] = arr[st[k]];
        }
        ans.back() = -1;
        return ans;
    }
};
