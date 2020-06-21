class Solution {
public:
    bool isPossible(vector<int>& nums) {
        vector<pair<int, int>> be;

        for (const int& n: nums) {
            bool nf(true);
            for (int i = be.size() - 1; i >= 0; --i)
                if (be[i].second == n - 1) {
                    nf = false;
                    be[i].second++;
                    break;
                }
            if (nf) be.push_back({n, n});
        }

        for (const auto& [b, e]: be)
            if (e - b < 2)
                return false;
        return true;
    }
};
