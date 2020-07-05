class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int i = 1;
        while (i < intervals.size()) {
            if (intervals[i][1] <= intervals[i - 1][1]) {
                intervals.erase(intervals.begin() + i);
            } else {
                i++;
            }
        }
        return intervals.size();
    }
};
