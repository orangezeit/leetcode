class Solution {
public:
    bool check(const vector<int>& nums, int k, double x) {
        vector<double> a(nums.begin(), nums.end());
        for (double& i: a) i -= x;
        //for (double& i: a) cout << i << ' ';
        double s(0), leftmost(0);
        for (int i = 0; i < k; ++i) s += a[i];
        if (s >= 0) return true;
        for (int i = k; i < nums.size(); ++i) {
            s += a[i];
            leftmost += a[i-k];
            if (leftmost < 0) {
                s -= leftmost;
                leftmost = 0;
            }
            if (s >= 0) return true;
        }
        return false;
    }
    double findMaxAverage(vector<int>& nums, int k) {
        double left(-10000.0), right(10000.0);
        //int x(2);
        while (right - left > 1e-6) {
            double mid = (left + right) / 2;
            check(nums, k, mid) ? left = mid : right = mid;
            //if (--x == 0)break;
        }
        return left;
    }
};
