class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& sp, int start, int end) {
        vector<vector<pair<int, double>>> g(n);
        for (int i = 0; i < edges.size(); ++i) {
            g[edges[i][0]].push_back({edges[i][1],sp[i]});
            g[edges[i][1]].push_back({edges[i][0],sp[i]});
        }
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start});
        vector<double> pb(n);
        pb[start] = 1.0;

        while (!pq.empty()) {
            double p = pq.top().first;
            int x = pq.top().second;
            if (x == end) return p;

            pq.pop();
            if (pb[x] - 1e-5 > p) continue;
            pb[x] = p;

            for (const auto& [nxt, np]: g[x])
                if (p * np > pb[nxt] + 1e-5)
                    pq.push({p * np, nxt});
        }

        return 0.0;
    }
};
