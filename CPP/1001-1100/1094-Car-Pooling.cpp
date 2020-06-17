class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int pick(0);
        map<int, int> road;

        for (const vector<int>& trip: trips) {
            road[trip[1]] += trip[0];
            road[trip[2]] -= trip[0];
        }

        for (const auto& [k, v]: road) {
            pick += v;
            if (pick > capacity) return false;
        }
        return true;
    }
};
