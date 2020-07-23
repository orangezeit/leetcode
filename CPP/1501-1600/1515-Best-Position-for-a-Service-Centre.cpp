// Solution 1: Descending Gradient
class Solution {
public:
    double getMinDistSum(vector<vector<int>>& ps) {
        auto cost = [&](long double x, long double y) {
            long double ans(0);
            for (const auto& p: ps)
                ans += sqrtl((x - p[0]) * (x - p[0]) + (y - p[1]) * (y - p[1]));
            return ans;
        };
        int n(ps.size());
        long double x0(0), y0(0), lr(0.5), eps(1e-8);
        for (const auto& p: ps) {
            x0 += p[0];
            y0 += p[1];
        }
        x0 /= n; y0 /= n;
        long double c0(cost(x0, y0));
        while (true) {
            long double dx(0), dy(0);
            for (const auto& p: ps) {
                long double x = sqrtl((x0 - p[0]) * (x0 - p[0]) + (y0 - p[1]) * (y0 - p[1]));
                dx += (x0 - p[0]) / max(1e-9L, x);
                dy += (y0 - p[1]) / max(1e-9L, x);
            }
            long double nx(x0 - dx * lr), ny(y0 - dy * lr), nc(cost(nx, ny));

            if (c0 - nc > eps) {
                c0 = nc;
                x0 = nx;
                y0 = ny;
            } else if (c0 - nc < 0) {
                lr *= 0.05;
            } else break;
        }
        return c0;
    }
};

// Solution 2: Trinary search
class Solution {
public:
    double getMinDistSum(vector<vector<int>>& ps) {
        auto cost = [&](long double x, long double y) {
            long double ans(0);
            for (const auto& p: ps)
                ans += sqrtl((x - p[0]) * (x - p[0]) + (y - p[1]) * (y - p[1]));
            return ans;
        };
        auto trinary = [&](long double x) {
            long double yl(0), yr(100);
            while (yr - yl > 1e-6) {
                long double first(yl + (yr - yl) / 3), second(yr - (yr - yl) / 3);
                cost(x, first) > cost(x, second) ? yl = first : yr = second;
            }
            return cost(x, yl);
        };
        long double xl(0), xr(100);
        while (xr - xl > 1e-6) {
            long double first(xl + (xr - xl) / 3), second(xr - (xr - xl) / 3);
            trinary(first) > trinary(second) ? xl = first : xr = second;
        }
        return trinary(xl);
    }
};

// Solution 3: Annealing
class Solution {
public:
    double getMinDistSum(vector<vector<int>>& ps) {
        auto cost = [&](long double x, long double y) {
            long double ans(0);
            for (const auto& p: ps)
                ans += sqrtl((x - p[0]) * (x - p[0]) + (y - p[1]) * (y - p[1]));
            return ans;
        };
        const int dirs[5] = {0, 1, 0, -1, 0};
        const long double lr = 0.5;

        long double x(0), y(0), c(1e18), step(100);

        while (step > 1e-6) {
            bool flag(true);
            while (flag) {
                flag = false;
                for (int i = 0; i < 4; i++) {
                    long double nx = x + dirs[i] * step;
                    long double ny = y + dirs[i + 1] * step;
                    long double tmp = cost(nx, ny);
                    if (tmp < c) {
                        c = tmp;
                        x = nx;
                        y = ny;
                        flag = true;
                    }
                }
            }
            step *= lr;
        }
        return c;
    }
};
