class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if (x <= arr[0]) {
            arr.resize(k);
            return arr;
        }

        int i = 0;
        int j = arr.size() - 1;

        while (j - i > 1) {
            int m = (i + j) / 2;
            arr[m] <= x ? i = m : j = m;
        }

        if (2 * x > arr[i] + arr[j]) i = j;
        int left = -1;
        int right = 1;

        while (--k) {
            i + left < 0 ? right++ : i + right == arr.size() ? left-- : 2 * x <= arr[i + left] + arr[i + right] ? left-- : right++;
        }

        return vector<int>(arr.begin() + i + left + 1, arr.begin() + i + right);
    }
};
