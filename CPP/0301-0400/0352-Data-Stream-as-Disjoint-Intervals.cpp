class SummaryRanges {
public:
    /** Initialize your data structure here. */
    map<int, int> m;
    unordered_set<int> added;
    SummaryRanges() {

    }

    void addNum(int val) {
        if (added.count(val)) return;
        added.insert(val);
        m[val]++;
        m[val+1]--;
        if (!m[val]) m.erase(val);
        if (!m[val+1]) m.erase(val+1);
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for (const auto p: m) {
            //cout << p.first << " " << p.second << endl;
            if (p.second == 1) ans.push_back({p.first, -1});
            else ans.back()[1] = p.first - 1;
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
