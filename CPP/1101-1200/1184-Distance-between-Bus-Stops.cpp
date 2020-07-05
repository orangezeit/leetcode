class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if (start > destination) swap(start, destination);
        int clock(0), counter(0);
        for (int i = 0; i < distance.size(); ++i) {
            if (i >= start && i < destination) clock += distance[i];
            else counter += distance[i];
        }
        return min(clock, counter);
    }
};
