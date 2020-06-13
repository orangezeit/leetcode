class Solution {
public:
    unordered_map<int, int> rec;

    int dfs(int state, int w, const vector<vector<int>>& workers, const vector<vector<int>>& bikes) {
        if (w == workers.size()) return 0;
        if (rec.count(state)) return rec[state];

        int minVal(INT_MAX), dist(0);

        for (int i = 0; i < bikes.size(); ++i) {
            if (!(state & (1 << i))) {
                dist = abs(bikes[i][0] - workers[w][0]) + abs(bikes[i][1] - workers[w][1]);
                minVal = min(minVal, dfs(state | (1 << i), w + 1, workers, bikes) + dist);
            }
        }

        return rec[state] = minVal;
    }

    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n(workers.size());
        return dfs(0, 0, workers, bikes);
    }
};
