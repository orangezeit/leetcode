class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> hc(heights);
        int k(0);
        sort(heights.begin(), heights.end());
        for (int i = 0; i < heights.size(); ++i)
            k += heights[i] != hc[i];
        return k;
    }
};
