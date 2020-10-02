class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        // Time Complexity: O(N)
        // Space Complexity: O(1)
        int n(arr.size()), left1(0), right1(n - 1), ans(n - 1);
        while (left1 < n - 1 && arr[left1 + 1] >= arr[left1]) left1++;
        if (left1 == n - 1) return 0;
        ans = min(ans, n - left1 - 1);
        while (right1 > 0 && arr[right1 - 1] <= arr[right1]) right1--;
        ans = min(ans, right1);
        int left2(left1), right2(right1);
        while (left2 >= 0 && arr[left2] > arr[right1]) left2--;
        ans = min(ans, right1 - left2 - 1);
        while (right2 <= n - 1 && arr[right2] < arr[left1]) right2++;
        ans = min(ans, right2 - left1 - 1);
        return ans;
    }
};
