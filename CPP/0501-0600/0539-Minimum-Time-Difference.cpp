class Solution {
public:
    int findMinDifference(vector<string>& ts) {
        int n(ts.size()), ans(720);
        vector<int> stamps(n);

        for (int i = 0; i < n; ++i)
            stamps[i] = stoi(ts[i].substr(0, 2)) * 60 + stoi(ts[i].substr(3));

        sort(stamps.begin(), stamps.end());
        stamps.emplace_back(stamps[0] + 1440);

        for (int i = 0; i < n; ++i)
            ans = min(ans, stamps[i + 1] - stamps[i]);

        return ans;
    }
};
