class Solution {
public:
    int minDays(vector<int>& b, int m, int k) {
        if (b.size() < m * k) return -1;
        int left(1), right(*max_element(b.begin(), b.end()));
        function<bool(int)> check = [&](int x) {
            vector<int> v(1);
            for (const int& i: b)
                if (i > x) {
                    if (v.back()) v.push_back(0);
                } else {
                    v.back()++;
                }
            int c(0);
            for (const int& i: v) c += i / k;
            return c >= m;
        };

        while (left < right) {
            int mid = (left + right) / 2;
            check(mid) ? right = mid : left = mid + 1;
        }
        return left;
    }
};
