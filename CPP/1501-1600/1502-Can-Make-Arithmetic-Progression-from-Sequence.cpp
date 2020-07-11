class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        // Time Complexity: O(N lg N)
        // Space Complexity: O(1)
        sort(arr.begin(), arr.end());
        for (int i = 2; i < arr.size(); ++i)
            if (c = arr[1] - arr[0] != arr[i] - arr[i-1])
                return false;
        return true;
    }
};
