class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        // map <presum: counts>
        // for k, [k + lower, k + higher], sum of counts
        multiset<long> s({0});
        int ans(0);
        long sum(0);

        for (const int& n: nums) {
            sum += n;
            ans += distance(s.lower_bound(sum - upper), s.upper_bound(sum - lower));
            s.insert(sum);
        }

        return ans;
    }
};
