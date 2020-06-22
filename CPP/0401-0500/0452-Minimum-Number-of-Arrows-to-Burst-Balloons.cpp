class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {return a[1] < b[1];});
        int arrow(1), target(points[0][1]);
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > target || target < points[i][1]) {
                arrow++;
                target = points[i][1];
            }
        }

        return arrow;
    }
};
