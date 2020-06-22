class Solution {
private:
    default_random_engine generator;
    double r, xc, yc;
    uniform_real_distribution<double> dist;
public:
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        xc = x_center;
        yc = y_center;
        dist = uniform_real_distribution<double>(-r, r);
    }

    vector<double> randPoint() {
        double xr, yr;

        do {
            xr = xc + dist(generator);
            yr = yc + dist(generator);
        } while ((xr - xc) * (xr - xc) + (yr - yc) * (yr - yc) > r * r);
        return {xr, yr};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj.randPoint();
 */
