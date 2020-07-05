class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int x = 0;
        int steps(0);
        int currMax(0);
        int nextMax(0);


        while (x <= currMax) {
            while (x <= currMax) {
                nextMax = max(nextMax, x + nums[x]);
                x++;
            }

            currMax = nextMax;
            steps++;
            if (currMax >= nums.size() - 1) return steps;
        }

        return 0;
    }
};
