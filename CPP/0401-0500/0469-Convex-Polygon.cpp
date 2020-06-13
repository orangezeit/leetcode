class Solution {
public:
    int cal(vector<int>&p1,vector<int>&p2,vector<int>&p3){
        return (p2[0]-p1[0])*(p3[1]-p1[1])-(p2[1]-p1[1])*(p3[0]-p1[0]);
    }

    bool isConvex(vector<vector<int>>& points) {
        points.push_back(points[0]);
        points.push_back(points[1]);
        long prev(0);

        for (int i = 1; i < points.size() - 1; ++i) {
            long c = cal(points[i - 1], points[i], points[i + 1]);
            if (c == 0) continue;
            if (c * prev < 0) return false;
            prev = c;
        }
        return true;
    }
};
