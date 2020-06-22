class Solution {
public:
    int findPoisonedDuration(vector<int>& ts, int duration) {
        int time(0), ep(0);

        for (const int& t: ts) {
            time += duration - max(ep - t, 0);
            ep = t + duration;
        }

        return time;
    }
};
