class Solution {
public:
    int makeArrayIncreasing(vector<int>& a, vector<int>& b) {
        const int INF = 1e9;
        sort(b.begin(), b.end());
        b.resize(unique(b.begin(), b.end()) - b.begin());
        int m(a.size()), n(b.size());

        vector<int> keeps(m, INF);
        keeps[0] = 0;
        vector<vector<int>> swaps(m, vector<int>(n, INF));
        fill(swaps[0].begin(), swaps[0].end(), 1);

        for (int i = 1; i < m; ++i) {
            int min_keep = INF;
            int min_swap = INF;
            for (int j = 0; j < n; ++j) {
                // res from swaps of a[:i] and b[:j], plus one swap of a[i] & b[j]
                if (j) min_swap = min(min_swap, swaps[i - 1][j - 1] + 1);
                // if a[i] > b[j], then not have to swap at (i, j)
                if (a[i] > b[j]) min_keep = min(min_keep, swaps[i - 1][j]);
                // if a[i] > a[i-1], we can keep a[i]
                if (a[i] > a[i - 1]) keeps[i] = keeps[i - 1];
                // if b[j] > a[i - 1], we can swap
                if (b[j] > a[i - 1]) swaps[i][j] = keeps[i - 1] + 1;
                swaps[i][j] = min(swaps[i][j], min_swap);
                keeps[i] = min(keeps[i], min_keep);
            }

        }
        int ans = min(*min_element(swaps.back().begin(), swaps.back().end()), keeps.back());

        return ans >= INF ? -1 : ans;
    }
};
