class Solution {
public:
    int maxArea(vector<int>& height) {
        int i(0), j(height.size() - 1), ma(0);

        while (i < j) {
            ma = max(ma, min(height[i], height[j]) * (j - i));
            height[i] < height[j] ? i++ : j--;
        }

        return ma;
    }
};
