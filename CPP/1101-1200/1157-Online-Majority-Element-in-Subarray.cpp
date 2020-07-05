class MajorityChecker {
public:
    unordered_map<int, vector<int>> indices;
    vector<int> a;
    MajorityChecker(vector<int>& arr) {
        a = arr;
        for (int i = 0; i < arr.size(); ++i)
            indices[arr[i]].push_back(i);
    }

    int query(int left, int right, int threshold) {

        for (int i = 0; i < 5; ++i) {
            int idx = a[left + rand() % (right - left + 1)];
            int d = distance(lower_bound(indices[idx].begin(), indices[idx].end(), left),
                             upper_bound(indices[idx].begin(), indices[idx].end(), right));
            if (d >= threshold) return idx;
        }

        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
