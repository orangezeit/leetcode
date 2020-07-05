const static double eps = 1e-6;

class Solution {
public:
    vector<vector<double>> intersect(const vector<int>& o1, const vector<int>& o2, const int& r) const {
        int d2((o1[0] - o2[0]) * (o1[0] - o2[0]) + (o1[1] - o2[1]) * (o1[1] - o2[1]));
        if (d2 > 4 * r * r) return {};

        vector<double> m({(o1[0] + o2[0]) / 2.0, (o1[1] + o2[1]) / 2.0});
        if (d2 == 4 * r * r) return {m};

        vector<int> v = {o1[1] - o2[1], o2[0] - o1[0]};
        double c = sqrt((double) r * r / d2 - 0.25);
        return {{m[0] + v[0] * c, m[1] + v[1] * c}, {m[0] - v[0] * c, m[1] - v[1] * c}};
    }

    bool inside(const vector<int>& o, const vector<double>& x, const int& r) const {
        return (o[0] - x[0]) * (o[0] - x[0]) + (o[1] - x[1]) * (o[1] - x[1]) < r * r + eps;
    }

    int numPoints(vector<vector<int>>& ps, int r) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n(ps.size()), ans(1);

        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                for (const vector<double>& x: intersect(ps[i], ps[j], r)) {
                    int cnt(0);
                    for (const vector<int>& o: ps)
                        if (inside(o, x, r))
                            cnt++;
                    ans = max(ans, cnt);
                }
        return ans;
    }
};
