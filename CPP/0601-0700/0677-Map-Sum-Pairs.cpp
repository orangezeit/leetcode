struct TrieNode {
    int n;
    unordered_map<char, TrieNode*> branchs;
    TrieNode(): n(0), branchs() {}
};

class MapSum {
public:
    TrieNode* ms = new TrieNode();
    unordered_map<string, int> rec;
    /** Initialize your data structure here. */
    MapSum() {

    }

    void insert(string key, int val) {
        val -= rec[key];
        rec[key] += val;
        TrieNode* temp = ms;
        for (const char& c: key) {
            if (!temp->branchs.count(c))
                temp->branchs[c] = new TrieNode();
            temp = temp->branchs[c];
            temp->n += val;
        }
    }

    int sum(string prefix) {
        TrieNode* temp = ms;
        for (const char& c: prefix) {
            if (!temp->branchs.count(c)) return 0;
            temp = temp->branchs[c];
        }
        return temp->n;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
