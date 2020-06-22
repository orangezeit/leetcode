class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mx(0), mask(0);
        for (int i = 31; i >= 0; --i) {
            // 11 ... 10 ... 0
            mask = mask | (1 << i);
            unordered_set<int> s;
            for (int n: nums) {
                s.insert(n & mask);
            }
            int tmp = mx | (1 << i);
            for (int i: s) {
                // tricky part: if a ^ b = c, then a ^ c = b
                if (s.count(tmp ^ i)) {
                    mx = tmp;
                    break;
                }
            }
        }
        return mx;
    }
};
