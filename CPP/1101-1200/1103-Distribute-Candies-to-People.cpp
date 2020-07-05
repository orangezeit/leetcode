class Solution {
public:
    vector<int> distributeCandies(int candies, int n) {
        int first = 1;
        int last = 44721;
        while (last - first > 1) {
            int mid = (first + last) / 2;
            if (mid * (mid + 1) / 2 > candies) {
                last = mid;
            } else {
                first = mid;
            }
        }

        vector<int> ans(n);
        int level = first / n;
        int r = first % n;

        for (int i = 0; i < n; ++i) {
            ans[i] = level * (level + (i < r ? 1 : -1)) / 2 * n + (level + (i < r)) * (i + 1);
        }
        ans[r] += candies - first * (first + 1) / 2;

        return ans;
    }
};
