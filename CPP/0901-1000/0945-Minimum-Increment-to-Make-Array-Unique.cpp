class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int ans(0);
        map<int, int> cnts;

        for (const int& i: A) cnts[i]++;
        for (auto& [k, v]: cnts)
            if (--v) {
                ans += v;
                cnts[k + 1] += v;
            }
        return ans;
    }
};
