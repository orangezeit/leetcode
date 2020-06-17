class Solution {
public:

    int dist(const string& a, const string& b) {
        for (int i = min(a.length(), b.length()); i >= 0; --i) {
            if (a.substr(a.length() - i) == b.substr(0, i))
                return b.length() - i;
        }
        return b.length();
    }

    string shortestSuperstring(const vector<string>& A) {
        int n(A.size());
        vector<vector<int>> info(n, vector<int>(n));
        vector<int> path, best;
        int len(0), minLen(INT_MAX);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (i != j) info[i][j] = dist(A[i], A[j]);

        // dp
        int k(1 << n);
        vector<vector<int>> dp(k, vector<int>(n, INT_MAX / 2));
        vector<vector<int>> parent(k, vector<int>(n, -1));
        // bitmask: strings already used (e.g. 11001 first, second, fifth used)
        // end with n-th string;

        // begin with i-th word
        for (int i = 0; i < n; ++i)
            dp[1 << i][i] = A[i].length();

        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) { // j-th string in bitmask
                    int prev = i - (1 << j);
                    for (int x = 0; x < n; ++x) {
                        if (x != j && (i & (1 << x))) {
                            if (dp[prev][x] + info[x][j] < dp[i][j]) {
                                dp[i][j] = dp[prev][x] + info[x][j];
                                parent[i][j] = x;
                            }
                        }
                    }
                }
            }
        }

        auto it = min_element(dp.back().begin(), dp.back().end());
        int cur = it - dp.back().begin();

        int s = (1 << n) - 1;
        string ans;
        while (s) {
            int prev = parent[s][cur];
            if (prev < 0) ans = A[cur] + ans;
            else ans = A[cur].substr(A[cur].length() - info[prev][cur]) + ans;
            s &= ~(1 << cur);
            cur = prev;
        }
        return ans;
    }
};
