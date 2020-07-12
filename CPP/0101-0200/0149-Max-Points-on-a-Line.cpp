class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() <= 2) return points.size();
        int res(1);
        for (int i = 0; i < points.size(); ++i) {
            map<pair<int, int>, int> slopes;
            int line(0);
            for (int j = 0; j < points.size(); ++j) {
                if (i == j) continue;
                int dx(points[j][0] - points[i][0]);
                int dy(points[j][1] - points[i][1]);
                int g(gcd(dx, dy));
                g ? line = max(line, ++slopes[{dx / g, dy / g}]) : line++;
            }
            res = max(res, line + 1);
        }

        return res;
    }
};
