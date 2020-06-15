class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int mid = n % 2 ? arr[n / 2] : arr[n / 2 - 1];
        sort(arr.begin(), arr.end(), [&](const int& a, const int& b) {
            return abs(a - mid) > abs(b - mid) || abs(a - mid) == abs(b - mid) && a > b;
        });
        arr.resize(k);
        return arr;
    }
};
