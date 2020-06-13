class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i + 1 < intervals.size(); ++i)
            if (intervals[i][1] > intervals[i+1][0])
                return false;
        return true;
    }
};
