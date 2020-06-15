class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        sort(s.rbegin(), s.rend());
        int ans(0);
        for (int i = 0; i < s.size(); ++i) {
            if (i) s[i] += s[i-1];
            if (s[i] < 0) return ans;
            ans += s[i];
        }
        return ans;
    }
};
