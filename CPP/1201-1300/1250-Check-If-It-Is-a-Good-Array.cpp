class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int g(nums[0]);
        for (const int& n: nums)
            if ((g = gcd(g, n)) == 1)
                return true;
        return false;
    }
};
