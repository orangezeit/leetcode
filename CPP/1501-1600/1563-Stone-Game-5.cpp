class Solution {
public:
    unordered_map<int, int> rec;
    int game(const vector<int>& presums, int begin, int end, const int& n) {
        if (rec.count(begin * n + end)) return rec[begin * n + end];
        if (begin + 1 == end) return rec[begin * n + end] = 0;

        int res = 0;
        for (int i = begin + 1; i < end; ++i) {
            int left(presums[i] - presums[begin]), right(presums[end] - presums[i]), r1(0), r2(0);
            if (left <= right) r1 = left + game(presums, begin, i, n);
            if (left >= right) r2 = right + game(presums, i, end, n);
            res = max(res, max(r1, r2));
        }
        return rec[begin * n + end] = res;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n(stoneValue.size());
        vector<int> presums(n + 1);

        for (int i = 1; i <= n; ++i)
            presums[i] = stoneValue[i - 1] + presums[i - 1];

        return game(presums, 0, n, n);
    }
};
