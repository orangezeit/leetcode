class RangeModule {
private:
    typedef map<int, int>::iterator it;
    map<int, int> ranges;
    void getOverlappedRanges(int left, int right, it& l, it& r) {
        l = ranges.upper_bound(left);
        r = ranges.upper_bound(right);
        if (l != ranges.begin() && (--l)->second < left) l++;
    }
public:
    RangeModule() {}

    void addRange(int left, int right) {
        it l, r;
        getOverlappedRanges(left, right, l, r);
        if (l != r) {
            left = min(left, l->first);
            right = max(right, prev(r)->second);
            ranges.erase(l, r);
        }
        ranges[left] = right;
    }

    bool queryRange(int left, int right) {
        it l, r;
        getOverlappedRanges(left, right, l, r);
        if (l == r) return false;
        return l->first <= left && right <= l->second;
    }

    void removeRange(int left, int right) {
        it l, r;
        getOverlappedRanges(left, right, l, r);
        if (l == r) return;
        int start = min(left, l->first);
        int end = max(right, prev(r)->second);
        ranges.erase(l, r);
        if (start < left) ranges[start] = left;
        if (right < end) ranges[right] = end;
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
