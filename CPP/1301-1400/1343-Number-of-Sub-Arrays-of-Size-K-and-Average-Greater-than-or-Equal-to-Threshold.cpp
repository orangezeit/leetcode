class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int avg(0), cnt(0);
        for (int i = 0; i < k; ++i) {
            avg += arr[i];
        }
        if (avg * 1.0 / k >= threshold || abs(avg * 1.0 / k - threshold) < 1e-6) cnt++;
        for (int i = k; i < arr.size(); ++i) {
            avg += arr[i];
            avg -= arr[i-k];
            if (avg * 1.0 / k >= threshold || abs(avg * 1.0 / k - threshold) < 1e-6) cnt++;
        }
        return cnt;
    }
};
