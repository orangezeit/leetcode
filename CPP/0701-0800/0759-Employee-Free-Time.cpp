/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        map<int, int> rec;
        vector<Interval> ans;

        for (const vector<Interval>& v: schedule)
            for (const Interval i: v) {
                rec[i.start]++;
                rec[i.end]--;
            }

        int accu(0);
        int b(-1);
        for (const auto& p: rec) {
            accu += p.second;
            //cout << accu << " ";
            if (!accu) {
                b = p.first;
            } else if (b >= 0) {
                //Interval* inv = ;
                ans.push_back(Interval(b, p.first));
                b = -1;

            }
        }
        return ans;


    }
};
