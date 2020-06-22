class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans(0);
        if (k > 0) {
            unordered_set<int> s(nums.begin(), nums.end());
            for (const int& i: s)
                if (s.count(i + k))
                    ans++;
        } else if (k == 0) {
            unordered_map<int, int> m;
            for (const int& i: nums)
                if (++m[i] == 2)
                    ans++;
        }
        return ans;
    }
};
