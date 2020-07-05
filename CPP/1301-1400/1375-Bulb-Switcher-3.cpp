class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int right(0), ans(0);
        for (int i = 0; i < light.size(); ++i) {
            right = max(right, light[i]);
            ans += right == i + 1;
        }
        return ans;
    }
};
