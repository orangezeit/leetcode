class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans(0), left(0);
        for (const int& i: target) {
            ans += max(i - left, 0);
            left = i;
        }
        return ans;
    }
};
