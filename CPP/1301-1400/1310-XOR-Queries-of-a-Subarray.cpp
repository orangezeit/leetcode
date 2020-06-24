class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<vector<int>> rec(arr.size(), vector<int>(32));
        int n(0);
        for (int i: arr) {
            vector<int> ds;
            while (i) {
                ds.push_back(i % 2);
                i /= 2;
            }
            for (int k = ds.size() - 1; k >= 0; --k) {
                rec[n][k] = ds[k];
            }

            if (n) {
                for (int k = 0; k < 32; ++k) {
                    rec[n][k] += rec[n - 1][k];
                }
            }

            n++;
        }

        vector<int> ans(queries.size());
        n = 0;
        for (vector<int> q: queries) {
            if (q[0]) {
                for (int k = 0; k < 32; ++k) {
                    if ((rec[q[1]][k] - rec[q[0] - 1][k]) % 2) {
                        ans[n] += (1 << k);
                    }
                }
            } else {
                for (int k = 0; k < 32; ++k) {
                    if (rec[q[1]][k] % 2) {
                        ans[n] += (1 << k);
                    }
                }
            }
            n++;
        }
        return ans;
    }
};
