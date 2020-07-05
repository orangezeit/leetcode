class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int ones(0);
        for (const int& col: colsum)
            if (col == 2) {
                if ((--upper) < 0 || (--lower) < 0) return {};
            } else if (col == 1) {
                ones++;
            }

        if (upper + lower != ones) return {};

        vector<vector<int>> ans(2, vector<int>(colsum.size()));

        for (int i = 0; i < colsum.size(); ++i)
            if (colsum[i] == 2)
                ans[0][i] = ans[1][i] = 1;
            else if (colsum[i] == 1)
                (upper > 0 && upper--) ? ans[0][i] = 1 : ans[1][i] = 1;

        return ans;
    }
};
