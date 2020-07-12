class Solution {
public:
    int candy(vector<int>& ratings) {
        const int n(ratings.size());
        vector<int> ans(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i - 1])
                ans[i] = ans[i - 1] + 1;
        }
        for (int i = ratings.size() - 2; i >= 0; --i) {
            if (ratings[i + 1] < ratings[i])
                ans[i] = max(ans[i], ans[i + 1] + 1);
        }
        int res(0);
        for (const int& i: ans) res += i;
        return res;
    }
};
