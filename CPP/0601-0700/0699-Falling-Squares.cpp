class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> ans;
        map<pair<int, int>, int> b; // {{start, end}, height}
        int max_h(INT_MIN);

        for (const auto& kv: positions) {
            int start = kv[0];
            int end = kv[0] + kv[1];

            auto it = b.upper_bound({start, end});
            if (it != b.begin() && prev(it)->first.second > start)
                --it;

            int base_h(0);
            vector<array<int, 3>> ranges;
            while (it != b.end() && it->first.first < end) {
                // start, end, height
                const int s = it->first.first;
                const int e = it->first.second;
                const int h = it->second;
                if (s < start) ranges.push_back({s, start, h});
                    //b[{s, start}] = h;
                if (e > end) ranges.push_back({end, e, h});
                    //b[{e, end}] = h;
                base_h = max(base_h, h);
                it = b.erase(it);
            }
            for (const auto&[s, e, h]: ranges)
                b[{s, e}] = h;
            int new_h = base_h + kv[1];
            b[{start, end}] = new_h;
            max_h = max(max_h, new_h);
            ans.push_back(max_h);
        }

        return ans;
    }
};
