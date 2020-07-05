class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long sum(0), m1(0), m2(0);
        long total(0);

        for (const int& i: arr) {
            m1 = max(m1, sum = max(sum + i, 0L));
            total += i;
        }

        if (k == 1) return m1;

        for (const int& i: arr)
            m2 = max(m2, sum = max(sum + i, 0L));
        if (total > 0) m2 += (k - 2) * total % 1000000007;
        return max(m1, m2) % 1000000007;
    }
};
