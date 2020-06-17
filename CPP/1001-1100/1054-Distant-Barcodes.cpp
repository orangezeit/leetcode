class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> rec;
        int n(barcodes.size());

        for (const int& c: barcodes) rec[c]++;

        priority_queue<pair<int, int>> pq;

        for (const auto& [k, v]: rec) {
            pq.push({v, k});
        }

        vector<int> ans(n);

        for (int i = 0; i < n - 1; i += 2) {
            pair<int, int> p1 = pq.top();
            pq.pop();
            pair<int, int> p2 = pq.top();
            pq.pop();

            ans[i] = p1.second;
            ans[i + 1] = p2.second;

            if (--p1.first) pq.push(p1);
            if (--p2.first) pq.push(p2);
        }

        if (n % 2) ans.back() = pq.top().second;
        return ans;

    }
};
