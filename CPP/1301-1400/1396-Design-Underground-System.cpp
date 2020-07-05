class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> timestamps;
    unordered_map<string, int> times, trips;
    UndergroundSystem() {

    }

    void checkIn(int id, string sn, int t) {
        timestamps[id] = {sn, t};
    }

    void checkOut(int id, string sn, int t) {
        string str = timestamps[id].first + sn;
        times[str] += t - timestamps[id].second;
        trips[str]++;
        timestamps.erase(id);
    }

    double getAverageTime(string ss, string es) {
        string str(ss + es);
        return (double) times[str] / trips[str];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
