class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        map<int, int> rec;

        for (const vector<int>& s1: slots1) {
            rec[s1[0]]++;
            rec[s1[1]]--;
        }

        for (const vector<int>& s2: slots2) {
            rec[s2[0]]++;
            rec[s2[1]]--;
        }

        int c(0), prev(-1), temp(-1);

        for (const auto& p: rec) {
            c += p.second;
            if (c == 2)
                temp = p.first;
            else if (prev == 2 && temp != -1) {
                if (p.first - temp >= duration)
                    return {temp, temp + duration};
                temp = -1;
            }

            prev = c;
        }

        return {};
    }
};
