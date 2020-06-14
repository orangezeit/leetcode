class LogSystem {
public:
    map<string, int> record;
    LogSystem() {

    }

    void put(int id, string timestamp) {
        record[timestamp] = id;
    }

    vector<int> retrieve(string s, string e, string gra) {
        unordered_set<int> timestamps;
        int k = 0;
        if (gra == "Year") {
            k = 4;
        } else if (gra == "Month") {
            k = 7;
        } else if (gra == "Day") {
            k = 10;
        } else if (gra == "Hour") {
            k = 13;
        } else if (gra == "Minute") {
            k = 16;
        } else {
            k = 19;
        }
        s = s.substr(0, k);
        e = e.substr(0, k);
        cout << s << " " << e << endl;
        for (auto it = record.begin(); it != record.end(); ++it) {
            string str = it->first.substr(0, k);
            if (str >= s && str <= e) timestamps.insert(it->second);
        }
        return vector<int>(timestamps.begin(), timestamps.end());
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(s,e,gra);
 */
