class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        vector<int> a(2), b(2);
        double s = 0.0;

        for (int i = 0; i < points.size() - 2; ++i) {
            for (int j = i + 1; j < points.size() - 1; ++j) {
                for (int k = j + 1; k < points.size(); ++k) {
                    a[0] = points[i][0] - points[j][0];
                    a[1] = points[i][1] - points[j][1];
                    b[0] = points[i][0] - points[k][0];
                    b[1] = points[i][1] - points[k][1];

                    if (s < abs(a[0] * b[1] - a[1] * b[0]) / 2.0) {
                        s = abs(a[0] * b[1] - a[1] * b[0]) / 2.0;
                    }
                }
            }
        }

        return s;
    }
};
