class Solution {
public:
    int hIndex(vector<int>& citations) {
        const int n = citations.size();
        int left(0), right(n);
        while (left < right) {
            int mid = (left + right) / 2;
            if (mid >= citations[n - mid - 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
