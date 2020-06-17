class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        priority_queue<vector<int>> pq;
        for (vector<int>& cost: costs) {
            cost.insert(cost.begin(), cost[0] - cost[1]);
            pq.push(cost);
        }

        int ans(0);

        while (!pq.empty()) {
            ans += pq.size() <= costs.size() / 2 ? pq.top()[1] : pq.top()[2];
            pq.pop();
        }

        return ans;
    }
};
