class Solution {
public:
    int maximumSum(vector<int>& arr) {
        auto res = INT_MIN, s1 = 0, s2 = 0, m1 = 0, m2 = 0;
        for (const int& n : arr) {
            if (s1 < 0) s1 = m1 = 0;
            if (s2 <= m2) s2 = m2 = 0;
            s1 += n, s2 += n;
            res = max(res, max(s1 - m1, s2 - m2));
            m1 = min(m1, n);
            m2 = min(m2, n);
        }
        return res;
    }
};
