class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> rec;
        for (const int& i: arr) rec[i]++;
        int n(arr.size()), m(rec.size()), i(0), s(0);
        vector<pair<int, int>> rec2(m);

        for (const auto& [k, v]: rec) {
            rec2[i].first = v;
            rec2[i].second = k;
            i++;
        }
        sort(rec2.rbegin(), rec2.rend());

        for (int i = 0; i < m; ++i) {
            s += rec2[i].first;
            if (s >= n / 2) return i + 1;
        }
        return m;
    }
};
