class LRUCache {
public:
    // key: {val, iter}
    unordered_map<int, pair<int, list<int>::iterator>> record;
    list<int> lru; // most recent key to less recent key;
    int c;

    LRUCache(int capacity) {
        c = capacity;
    }

    int get(int key) {
        if (record.count(key)) {
            int val = record[key].first;
            lru.erase(record[key].second);
            lru.push_front(key);
            record[key] = {val, lru.begin()};
            return val;
        }

        return -1;
    }

    void put(int key, int value) {
        if (record.count(key)) {
            lru.erase(record[key].second);
            lru.push_front(key);
            record[key] = {value, lru.begin()};
            return;
        } else if (lru.size() == c) {
            record.erase(lru.back());
            lru.pop_back();
        }
        lru.push_front(key);
        record[key] = {value, lru.begin()};

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
