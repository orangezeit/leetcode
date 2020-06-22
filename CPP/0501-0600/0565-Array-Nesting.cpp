class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n(nums.size()), ans(0);
        vector<bool> visited(n);
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            int steps(0);
            while (!visited[i]) {
                visited[i] = true;
                i = nums[i];
                ans = max(ans, ++steps);
            }
        }
        return ans;
    }
};
