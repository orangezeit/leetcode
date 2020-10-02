class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int sum(0), mx(0), ans(0);
        for (int i = 0; i < s.length(); ++i) {
            if (i && s[i - 1] == s[i]) {
                sum += cost[i];
                mx = max(mx, cost[i]);
            } else {
                ans += sum - mx;
                sum = cost[i];
                mx = cost[i];
            }
        }
        return ans + sum - mx;
    }
};
