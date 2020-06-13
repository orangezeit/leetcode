class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        stack<int> s;
        int ans(0);
        for (const int& n: nums) {
            while (!s.empty() && s.top() > n) s.pop();
            s.push(n);
            ans += s.size();
        }
        return ans;
    }
};
