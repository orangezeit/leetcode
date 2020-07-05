class SnapshotArray {
private:
    int cnt;
    unordered_map<int, map<int, int>> hist;
public:
    SnapshotArray(int length) {
        cnt = 0;
        for (int i = 0; i < length; ++i)
            hist[i][0] = 0;
    }

    void set(int index, int val) {
        hist[index][cnt] = val;
    }

    int snap() {
        return cnt++;
    }

    int get(int index, int snap_id) {
        return (--hist[index].upper_bound(snap_id))->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
