class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        set<int> sorted(nums.begin(), nums.end());
        unordered_map<int, int> ranks;
        int rank(0);
        for (const int& i: sorted)
            ranks[i] = ++rank;

        vector<int> fenwick(ranks.size() + 1), ans(nums.size());
        int k(nums.size() - 1);
        reverse(nums.begin(), nums.end());
        for (int n: nums) {
            // update fenwick
            for (int i = ranks[n]; i <= ranks.size(); i += i & (-i)) {
                fenwick[i]++;
            }

            // query
            for (int i = ranks[n] - 1; i > 0; i -= i & (-i)) {
                ans[k] += fenwick[i];
            }
            k--;
        }
        return ans;
    }
};
