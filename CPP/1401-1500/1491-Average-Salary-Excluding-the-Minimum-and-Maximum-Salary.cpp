class Solution {
public:
    double average(vector<int>& salary) {
        int n(salary.size()), mn(INT_MAX), mx(INT_MIN);
        double s(0);
        for (const int& i: salary) {
            mn = min(mn, i);
            mx = max(mx, i);
            s += i;
        }
        return (s - mn - mx) / (n - 2);
    }
};
