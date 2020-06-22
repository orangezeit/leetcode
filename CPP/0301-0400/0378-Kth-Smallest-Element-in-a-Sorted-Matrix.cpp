class Solution {
public:
    int lex(int x, vector<vector<int>>& matrix, const int& k) {
        int sum(0);
        int n(matrix.size());
        //cout << x << endl;
        for (int i = 0; i < n; ++i) {
            sum += upper_bound(matrix[i].begin(), matrix[i].end(), x) - matrix[i].begin();
            //sum += min(n, x / i);
        }

        return sum;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (k == 1) return matrix[0][0];
        int l(matrix[0][0]), r(matrix.back().back() + 1);

        while (l < r) {
            int mid = (l + r) / 2;
            if (lex(mid, matrix, k) >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};
