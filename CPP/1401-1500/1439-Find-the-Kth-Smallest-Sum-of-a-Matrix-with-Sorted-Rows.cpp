class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {

        const int m(mat.size()), n(mat[0].size()), mod(1e9 + 7);
        deque<vector<int>> pdq;

        vector<int> info(m + 2);
        long mod_pows[m];

        int s(0);
        for (int i = 0; i < m; ++i) s += mat[i][0];
        info[0] = s;

        for (int i = 0; i < m; ++i)
            mod_pows[i] = i ? mod_pows[i - 1] * n % mod : 1;

        pdq.push_back(info);
        unordered_set<int> hashs({info[m + 1]});

        while (--k) {
            vector<int> p = pdq.front();
            pdq.pop_front();
            //hashs.erase(p[m + 1]);

            for (int i = 1; i <= m; ++i) {
                if (p[i] + 1 < n) {
                    p[0] -= mat[i - 1][p[i]] - mat[i - 1][++p[i]];
                    int h = (p[m + 1] + mod_pows[m - i]) % mod;
                    if (!hashs.count(h)) {
                        int temp = p[m + 1];
                        p[m + 1] = h;

                        pdq.insert(lower_bound(pdq.begin(), pdq.end(), p), p);
                        if (pdq.size() > k) {
                            //hashs.erase(pdq.back()[m + 1]);
                            pdq.pop_back();
                        }
                        hashs.insert(h);
                        p[m + 1] = temp;
                    }
                    p[0] -= mat[i - 1][p[i]]- mat[i - 1][--p[i]];

                }
            }
        }

        return pdq.front()[0];
    }
};
