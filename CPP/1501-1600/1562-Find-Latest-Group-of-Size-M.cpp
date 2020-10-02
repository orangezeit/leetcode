class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n(arr.size()), ans(-1);
        map<int, int> mp; // begin: end
        unordered_map<int, int> rec; // length: count
        for (int i = 0; i < n; ++i) {
            auto [iter, existed] = mp.insert({arr[i], arr[i]});
            int len(1);
            if (iter != mp.begin() && prev(iter)->second == arr[i]-1) {
                iter = prev(iter);
                int x = ++(iter->second) - iter->first;
                if (--rec[x] == 0) rec.erase(x);
                len += x;
                mp.erase(next(iter));
            }
            if (next(iter) != mp.end() && next(iter)->first == arr[i]+1) {
                int x = next(iter)->second - next(iter)->first + 1;
                if (--rec[x] == 0) rec.erase(x);
                len += x;
                iter->second = next(iter)->second;
                mp.erase(next(iter));
            }
            rec[len]++;
            if (rec.count(m)) ans = max(ans, i + 1);
        }
        return ans;
    }
};
