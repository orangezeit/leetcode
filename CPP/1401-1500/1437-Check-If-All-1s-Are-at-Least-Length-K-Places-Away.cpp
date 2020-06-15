class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int i = -1;

        for (int j = 0; j < nums.size(); ++j)
            if (nums[j] == 1) {
                if (i != -1 && j - i - 1 < k)
                    return false;
                i = j;
            }

        return true;
    }
};
