class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int x(0), i(0);
        while (k--) {
            while (i < arr.size() && arr[i] == x + 1) {
                i++; x++;
            }
            x++;
        }
        return x;
    }
};
