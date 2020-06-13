struct tri {
    int dist;
    int worker;
    int bike;
};
class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<bool> ws(workers.size(), true), bs(bikes.size(), true);
        vector<int> ans(workers.size());
        vector<tri> tris(workers.size() * bikes.size());
        int k = 0;

        for (int i = 0; i < workers.size(); ++i) {
            for (int j = 0; j < bikes.size(); ++j) {
                tri t;
                t.dist = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
                t.worker = i;
                t.bike = j;
                tris[k++] = t;
            }
        }

        sort(tris.begin(), tris.end(), [](const tri& a, const tri& b)
        {
            return a.dist != b.dist ? a.dist < b.dist : a.worker != b.worker ? a.worker < b.worker : a.bike < b.bike;
        });

        for (int i = 0; i < tris.size(); ++i) {
            tri temp = tris[i];
            if (ws[temp.worker] && bs[temp.bike]) {
                ans[temp.worker] = temp.bike;
                ws[temp.worker] = false;
                bs[temp.bike] = false;
            }
        }

        return ans;
    }
};
