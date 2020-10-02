#define INF 0x3f3f3f3f

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        vector<bool> vis(n);
        vector<int> min_dist(n, INF);
        min_dist[0] = 0;
        for (int i = 0; i < n; ++i) {
            int u = -1;
            int gmin = INF;
            for (int j = 0; j < n; ++j) {
                if (!vis[j] && min_dist[j] <= gmin) {
                    gmin = min_dist[j];
                    u = j;
                }
            }
            ans += gmin;
            vis[u] = true;
            for (int j = 0; j < n; ++j)
                if (!vis[j]) {
                    int new_dist = abs(points[j][0] - points[u][0]) + abs(points[j][1] - points[u][1]);
                    min_dist[j] = min(min_dist[j], new_dist);
                }
        }
        return ans;
    }
};
