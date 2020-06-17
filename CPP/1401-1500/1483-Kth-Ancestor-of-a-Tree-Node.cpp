class TreeAncestor {
int dp[50000][17];

public:
    TreeAncestor(int n, vector<int>& parent) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j <= 16; ++j)
                dp[i][j] = j ? -1 : parent[i];

        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= 16; ++j) {
                int p = dp[i][j-1];
                if (p != -1) dp[i][j] = dp[p][j-1];
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int j = 0; j <= 16; ++j) {
            if (k & (1 << j)) {
                node = dp[node][j];
                if (node == -1) return -1;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
