class Solution {
public:
    vector<int> cheapestJump(vector<int>& a, int b) {
        if (a.back() == -1) return {};
        int n(a.size());
        vector<int> scores(n, 100001);
        scores[n - 1] = a.back();
        vector<int> path(n);

        for (int i = n - 2; i >= 0; --i) {
            if (a[i] == -1) continue;
            for (int k = 1; k <= min(b, n - i - 1); ++k) {
                if (scores[i + k] + a[i] < scores[i]) {
                    scores[i] = scores[i + k] + a[i];
                    path[i] = i + k;
                }
            }
        }
        vector<int> ans;
        int i(0);
        while (path[i]) {
            ans.push_back(i + 1);
            i = path[i];
        }
        if (i == n - 1) ans.push_back(n);
        return ans;
    }
};
