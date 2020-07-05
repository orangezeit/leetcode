class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k) return false;
        map<int, int> rec;
        for (int n: nums) rec[n]++;
        while (!rec.empty()) {
            auto it = rec.begin();
            int x = it->first;
            for (int i = 0; i < k; ++i) {
                if (rec.count(x + i)) {
                    if (!(--rec[x + i])) rec.erase(x + i);
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};
