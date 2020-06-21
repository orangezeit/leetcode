class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int x(0);
        for (const int& n: nums) x ^= n;
        return !x || !(nums.size() % 2);
    }
};
