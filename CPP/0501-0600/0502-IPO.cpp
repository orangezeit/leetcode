class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        priority_queue<int> pq;
        vector<pair<int, int>> tasks(Profits.size());
        for (int i = 0; i < tasks.size(); ++i) {
            tasks[i].first = Capital[i];
            tasks[i].second = Profits[i];
        }
        sort(tasks.begin(), tasks.end());

        int i(0), ans(0);
        while (k--) {
            while (i < tasks.size() && tasks[i].first <= W) {
                pq.push(tasks[i].second);
                i++;
            }
            if (!pq.empty()) {
                W += pq.top();
                pq.pop();
            }
        }
        return W;
    }
};
