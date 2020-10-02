class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        vector<int> zeros;
        int n = grid.size();
        unordered_set<int> cnts;
        int ans(0);

        for (const vector<int>& row: grid) {
            int c(0);
            for (int i = n - 1; i >= 0; --i) {
                if (row[i]) break;
                c++;
            }
            zeros.push_back(c);
        }
        vector<int> zeros2(zeros);
        sort(zeros2.begin(), zeros2.end());
        for (int i = 0; i < n; ++i)
            if (zeros2[i] < i)
                return -1;

        // insertion sort
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (zeros[i] < zeros[j] && zeros[i] < n - i - 1) {
                    int t = zeros[j];
                    for (int k = j; k > i; --k)
                        zeros[k] = zeros[k - 1];
                    zeros[i] = t;
                    ans += j - i;
                }
            }
        }

        return ans;
    }
};
