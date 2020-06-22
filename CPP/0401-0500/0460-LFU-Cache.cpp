class LFUCache {
public:
    // key: {{value, freq}, iter}
    unordered_map<int, pair<pair<int, int>, list<int>::iterator>> record;
    vector<list<int>> lfu; // store keys
    int cnt;
    int c;
    int lf;

    LFUCache(int capacity) {
        c = capacity;
        cnt = 0;
        lfu.resize(1);
        lf = 0;
    }

    int get(int key) {
        if (!record.count(key)) return -1;
        int value = record[key].first.first;
        int freq = record[key].first.second;
        lfu[freq-1].erase(record[key].second);
        if (lfu[lf].empty()) lf++;
        if (lfu.size() == freq) lfu.resize(freq + 1);
        lfu[freq].push_front(key);
        record[key] = {{value, freq + 1}, lfu[freq].begin()};
        return value;
    }

    void put(int key, int value) {
        if (c == 0) return;
        if (record.count(key)) {
            get(key);
            record[key].first.first = value;
            return;
        }
        if (cnt == c) {
            cnt--;
            int temp = lfu[lf].back();
            lfu[lf].pop_back();
            record.erase(temp);
        }

        lfu[0].push_front(key);
        lf=0;
        record[key] = {{value, 1}, lfu[0].begin()};
        cnt++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
