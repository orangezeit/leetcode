class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        long long ans(0), sum(0);
        vector<array<int, 2>> ps(n);
        for (int i = 0; i < n; ++i) {
            ps[i][0] = efficiency[i];
            ps[i][1] = speed[i];
        }
        sort(ps.rbegin(), ps.rend());
        priority_queue<int, vector<int>, greater<int>> pq;
        for(const auto& [e, s]: ps) {
            sum += s;
            pq.push(s);
            while (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            ans = max(ans, sum * e);
        }

        return ans % 1000000007;
    }
};
