class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<int> coordinates;

        for (const vector<int>& p: points)
            coordinates.insert(p[0] + p[1] * 40001);

        int area = INT_MAX;

        for (const vector<int>& p1: points) {
            for (const vector<int>& p2: points) {
                if (p1[0] == p2[0] || p1[1] == p2[1] ||
                    !coordinates.count(p1[0] + p2[1] * 40001) || !coordinates.count(p2[0] + p1[1] * 40001)) continue;
                area = min(area, abs((p2[0] - p1[0]) * (p2[1] - p1[1])));
            }
        }

        return area == INT_MAX ? 0 : area;
    }
};
