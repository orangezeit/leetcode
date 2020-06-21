class Solution {
public:
    int bestRotation(vector<int>& A) {
        int n(A.size());
        vector<int> changes(n + 1);

        for (int i = 0; i < n; ++i) {
            changes[(i - A[i] + n + 1) % n]--;
            changes[i + 1]++;
        }
        int s(0), ans(0), res(0);
        for (int i = 1; i < n; ++i) {
            s += changes[i];
            if (s > res) {
                res = s;
                ans = i;
            }
        }
        return ans;
    }
};
