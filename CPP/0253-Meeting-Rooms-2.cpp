class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> record;
        for (const vector<int>& inv: intervals) {
            record[inv[0]]++;
            record[inv[1]]--;
        }
        int res(0), overlap(0);
        for (const auto& [k, v]: record)
            res = max(res, overlap += v);
        return res;
    }
};
