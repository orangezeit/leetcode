class TimeMap {
private:
    unordered_map<string, map<int, string>> rec;
public:
    /** Initialize your data structure here. */
    TimeMap() {
        rec.clear();
    }

    void set(string key, string value, int timestamp) {
        rec[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        //if (rec.find(key) == rec.end())
            //return "";
        return rec[key].begin()->first > timestamp ? "" : (--rec[key].upper_bound(timestamp))->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
