class AllOne {
public:
    unordered_map<string, int> record;
    /** Initialize your data structure here. */
    AllOne() {

    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        record[key]++;
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        record[key]--;
        if (!record[key] || record[key] == -1)
            record.erase(key);
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        //if (record.empty()) return "";
        int max_key(0);
        string key;
        for (auto it = record.begin(); it != record.end(); ++it) {
            if (it->second > max_key) {
                max_key = it->second;
                key = it->first;
            }
        }
        return key;
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        int min_key(INT_MAX);
        string key;
        for (auto it = record.begin(); it != record.end(); ++it) {
            if (it->second < min_key) {
                min_key = it->second;
                key = it->first;
            }
        }
        return key;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
