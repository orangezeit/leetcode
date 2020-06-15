class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        // Time Complexity: O(n)
        // Space Complexity: O(k)

        int n = nums.size();
        int sums[k][2];

        // 0: not choose nums[i], so we take max of sums[i-1][0], sums[i-1][1] (res from previous)
        // 1: choose nums[i], then have to choose some nums between nums[i-k] and nums[i-1]

        sums[0][0] = 0;
        sums[0][1] = nums[0];

        bool neg = nums[0] < 0;
        int least = nums[0];
        deque<int> dq({0});

        for (int i = 1; i < n; ++i) {
            sums[i % k][0] = max(sums[(i - 1) % k][0], sums[(i - 1) % k][1]);
            sums[i % k][1] = nums[i] + max(0, dq.empty() ? 0 : sums[dq.front() % k][1]);

            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();
            while (!dq.empty() && sums[dq.back() % k][1] <= sums[i % k][1])
                dq.pop_back();
            if (sums[i % k][1] > 0)
                dq.push_back(i);

            if (neg &= nums[i] < 0) least = max(least, nums[i]);
        }

        return neg ? least : max(sums[(n - 1) % k][0], sums[(n - 1) % k][1]);
    }
};
