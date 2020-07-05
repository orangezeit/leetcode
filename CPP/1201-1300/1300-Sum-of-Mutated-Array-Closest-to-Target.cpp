class Solution {
public:
    int cal(const vector<int>& arr, int x) {
        int s(0);
        for (const int& i: arr)
            s += min(x, i);
        return s;
    }

    int findBestValue(vector<int>& arr, int target) {
        int left(0), right(0);
        for (const int& i : arr)
            right = max(right, i);
        while (right - left > 1) {
            int mid = (left + right) / 2;
            cal(arr, mid) <= target ? left = mid : right = mid;
        }

        return cal(arr, right) - target >= target - cal(arr, left) ? left : right;
    }
};
