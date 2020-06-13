class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.size() == 0 || costs[0].size() == 0) return 0;
        vector<int> colors(costs[0].size());
        priority_queue<pair<int, int>> pq;
        
        for (int i = 0; i < colors.size(); ++i) {
            pq.push({0, i});
            if (pq.size() > 2) pq.pop();
        }
        
        for (const vector<int>& cost: costs) {
            vector<int> new_colors(colors.size());
            pair<int, int> smaller = pq.top();
            pq.pop();
            pair<int, int> smallest = pq.top();
            priority_queue<pair<int, int>> new_pq;
            
            for (int i = 0; i < cost.size(); ++i) {
                new_colors[i] = cost[i];
                new_colors[i] += i != smallest.second ? smallest.first : smaller.first;
                new_pq.push({new_colors[i], i});
                if (new_pq.size() > 2) new_pq.pop();
            }
            
            swap(colors, new_colors);
            swap(pq, new_pq);
        }
        
        pq.pop();
        
        return pq.top().first;
    }
};
