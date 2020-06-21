class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        map<pair<int, int>, vector<pair<int, int>>> m;

        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                dx > 0 ? m[{dx, dy}].push_back({i, j}) : m[{-dx, -dy}].push_back({j, i});
            }
        }

        double ans(1600000001.0);

        for (const auto& p: m) {
            for (const auto& p1: p.second) {
                for (const auto& p2: p.second) {
                    if (p1 >= p2) continue;
                    int i(p1.first), j(p1.second), k(p2.first);

                    int x1 = points[j][0] - points[i][0];
                    int y1 = points[j][1] - points[i][1];
                    int x2 = points[k][0] - points[i][0];
                    int y2 = points[k][1] - points[i][1];
                    if (x1 * x2 + y1 * y2) continue;
                    ans = min(ans, sqrt(x1 * x1 + y1 * y1) * sqrt(x2 * x2 + y2 * y2));
                }
            }
        }
        return ans > 1600000000 ? 0.0 : ans;
    }
};
