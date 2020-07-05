class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int ans(0);
        stack<int> s;

        for (int n: arr) {
            while (!s.empty() && s.top() < n) {
                int temp = s.top();
                s.pop();
                ans += s.empty() ? temp * n : temp * min(s.top(), n);
            }
            s.push(n);
        }

        while (s.size() >= 2) {
            int temp = s.top();
            s.pop();
            ans += temp * s.top();
        }

        return ans;
    }
};
