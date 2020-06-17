class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> cnts;
        for (const int& i: arr) cnts[i]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (const auto&[key, val]: cnts)
            pq.push({val, key});
        while (true) {
            int v = pq.top().first;
            pq.pop();
            int x = min(v, k);
            k -= x;
            if (!k) return pq.size() + (v - x ? 1 : 0);
        }
        return -1;
    }
};
